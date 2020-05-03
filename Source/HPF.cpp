/*
  ==============================================================================

    HPF.cpp
    Created: 2 Sep 2018 5:18:05pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "HPF.h"

//==============================================================================
HPF::HPF(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    hpfSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    hpfSlider.setRange(10.0f, 6000.0);
    hpfSlider.setValue(10.0f);
    hpfSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    hpfSlider.addListener(this);
    addAndMakeVisible(&hpfSlider);
    addAndMakeVisible(&hpfLabel);
    hpfLabel.attachToComponent(&hpfSlider, false);
    hpfLabel.setText("HPF", dontSendNotification);
    hpfLabel.setFont (Font (12.0f, Font::plain));
    hpfLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("0", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("5", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("10", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&zeroLabel2);
    zeroLabel2.setText("0", dontSendNotification);
    zeroLabel2.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel2);
    fiveLabel2.setText("5", dontSendNotification);
    fiveLabel2.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel2);
    tenLabel2.setText("10", dontSendNotification);
    tenLabel2.setFont (Font (numberFontSize, Font::bold));
    
    hfpVal = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (*processor.tree, "hpf", hpfSlider);

}

HPF::~HPF()
{
    hfpVal = nullptr;
}

void HPF::paint (Graphics& g)
{
   
}

void HPF::resized()
{
    tenLabel1.setBounds(0, 37.5, 20, 10);
    fiveLabel1.setBounds(5, 77.5, 20, 10);
    zeroLabel1.setBounds(5, 114, 20, 10);
    hpfSlider.setBounds(20, 30, sliderWidth, 100);
    tenLabel2.setBounds(sliderWidth  + 20, 37.5, 20, 10);
    fiveLabel2.setBounds(sliderWidth  + 20, 77.5, 20, 10);
    zeroLabel2.setBounds(sliderWidth + 20, 114, 20, 10);
}

void HPF::sliderValueChanged(Slider* slider)
{
    
}
