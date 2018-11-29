/*
  ==============================================================================

    Pulse.cpp
    Created: 3 Sep 2018 9:32:00pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PWM.h"

//==============================================================================
PWM::PWM(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    pwmSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    pwmSlider.setRange(0, 0.99f);
    pwmSlider.setValue(0);
    pwmSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    pwmSlider.addListener(this);
    addAndMakeVisible(&pwmSlider);
    addAndMakeVisible(&pwmLabel);
    pwmLabel.attachToComponent(&pwmSlider, false);
    pwmLabel.setText("PWM", dontSendNotification);
    pwmLabel.setFont (Font (12.0f, Font::plain));
    pwmLabel.setJustificationType(Justification::centred);
    
    pwmVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "pwm", pwmSlider);

}

PWM::~PWM()
{
}

void PWM::paint (Graphics& g)
{

}

void PWM::resized()
{
     pwmSlider.setBounds(0, 30, 50, 100);
}

void PWM::sliderValueChanged(Slider* slider)
{
    
}
