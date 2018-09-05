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
    
    pwmVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "pwm", pwmSlider);

}

PWM::~PWM()
{
}

void PWM::paint (Graphics& g)
{
   pwmSlider.setBounds(50, 30, 40, 100);
}

void PWM::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void PWM::sliderValueChanged(Slider* slider)
{
    
}
