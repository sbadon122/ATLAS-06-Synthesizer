/*
  ==============================================================================

    LFOPWM.cpp
    Created: 5 Sep 2018 4:22:56pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "LFOPWM.h"

//==============================================================================
LFOPWM::LFOPWM(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    lfoPwmSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    lfoPwmSlider.setRange(0, 0.99f);
    lfoPwmSlider.setValue(0);
    lfoPwmSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    lfoPwmSlider.addListener(this);
    addAndMakeVisible(&lfoPwmSlider);
    addAndMakeVisible(&lfoPwmLabel);
    lfoPwmLabel.attachToComponent(&lfoPwmSlider, false);
    lfoPwmLabel.setText("LFO", dontSendNotification);
    lfoPwmLabel.setFont (Font (12.0f, Font::plain));
    lfoPwmLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("0", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("5", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("10", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
    lfoPwmVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "lfoPwm", lfoPwmSlider);

}

LFOPWM::~LFOPWM()
{
}

void LFOPWM::paint (Graphics& g)
{
    
}

void LFOPWM::resized()
{
    tenLabel1.setBounds(0, 37.5, 20, 10);
    fiveLabel1.setBounds(5, 77.5, 20, 10);
    zeroLabel1.setBounds(5, 114, 20, 10);
    lfoPwmSlider.setBounds(20, 30, sliderWidth, 100);
}

void LFOPWM::sliderValueChanged(Slider* slider)
{
    
}
