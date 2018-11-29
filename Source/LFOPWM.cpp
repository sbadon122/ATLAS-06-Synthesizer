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
    lfoPwmLabel.setText("LFO PWM", dontSendNotification);
    lfoPwmLabel.setFont (Font (12.0f, Font::plain));
    lfoPwmLabel.setJustificationType(Justification::centred);
    
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
    lfoPwmSlider.setBounds(0, 30, 50, 100);
}

void LFOPWM::sliderValueChanged(Slider* slider)
{
    
}
