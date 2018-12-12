/*
  ==============================================================================

    VCA.cpp
    Created: 2 Sep 2018 9:59:37pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "VCA.h"

//==============================================================================
VCA::VCA(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    vcaSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    vcaSlider.setRange(0, 5.0f);
    vcaSlider.setValue(2.5f);
    vcaSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    addAndMakeVisible(&vcaSlider);
    addAndMakeVisible(&vcaLabel);
    vcaLabel.attachToComponent(&vcaSlider, false);
    vcaLabel.setText("VCA", dontSendNotification);
    vcaLabel.setFont (Font (12.0f, Font::plain));
    vcaLabel.setJustificationType(Justification::centred);
    
    vcaVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "vca", vcaSlider);
    
    ampModeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    ampModeSlider.setRange(0, 1);
    ampModeSlider.setValue(0);
    ampModeSlider.addListener(this);
    addAndMakeVisible(&ampModeSlider);
    addAndMakeVisible(&ampLabel);
    
    ampLabel.setText("AMP", dontSendNotification);
    ampLabel.setFont (Font (9.0f, Font::bold));
    
    
    addAndMakeVisible(&gateLabel);
    
    gateLabel.setText("GATE", dontSendNotification);
    gateLabel.setFont (Font (8.0f, Font::bold));
    
    
    
    ampModeVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "ampMode", ampModeSlider);
    
    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("-5", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("0", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("+5", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&zeroLabel2);
    zeroLabel2.setText("-5", dontSendNotification);
    zeroLabel2.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel2);
    fiveLabel2.setText("0", dontSendNotification);
    fiveLabel2.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel2);
    tenLabel2.setText("+5", dontSendNotification);
    tenLabel2.setFont (Font (numberFontSize, Font::bold));
    
    ampModeSlider.setLookAndFeel(&sliderToggleLookAndFeel);

}

VCA::~VCA()
{
    ampModeVal = nullptr;
    ampModeSlider.setLookAndFeel(nullptr);
}

void VCA::paint (Graphics& g)
{
}

void VCA::resized()
{
    ampLabel.setBounds(12, 40, 30, 30);
    ampModeSlider.setBounds(15, 60, 20, 30);
    gateLabel.setBounds(10, 80, 30, 30);
    tenLabel1.setBounds(38, 37.5, 20, 10);
    fiveLabel1.setBounds(43, 77.5, 20, 10);
    zeroLabel1.setBounds(40, 114, 20, 10);
    vcaSlider.setBounds(55, 30, sliderWidth, 100);
//    tenLabel1.setBounds(sliderWidth, 37.5, 20, 10);
//    fiveLabel1.setBounds(sliderWidth, 77.5, 20, 10);
//    zeroLabel1.setBounds(sliderWidth, 114, 20, 10);


}

void VCA::sliderValueChanged(Slider* slider)
{
    if(slider->getValue() == 1.0 || slider->getValue() == 0){
        return;
    }
    else if(slider->getValue() > 0.5){
        slider->setValue(1.0);
    } else {
        slider->setValue(0);
    }
}


