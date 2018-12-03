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
    
    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("0", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("5", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("10", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
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
     pwmSlider.setBounds(0, 30, sliderWidth, 100);
    tenLabel1.setBounds(sliderWidth, 37.5, 20, 10);
    fiveLabel1.setBounds(sliderWidth, 77.5, 20, 10);
    zeroLabel1.setBounds(sliderWidth, 114, 20, 10);
}

void PWM::sliderValueChanged(Slider* slider)
{
    
}
