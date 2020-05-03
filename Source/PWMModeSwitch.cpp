/*
  ==============================================================================

    PWMModeSwitch.cpp
    Created: 1 Dec 2018 1:50:56pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PWMModeSwitch.h"

//==============================================================================
PWMModeSwitch::PWMModeSwitch(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    pwmModeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    pwmModeSlider.setRange(0, 1);
    pwmModeSlider.setValue(0);
    pwmModeSlider.addListener(this);
    addAndMakeVisible(&pwmModeSlider);
    addAndMakeVisible(&pwmModeLabel);
   
    pwmModeLabel.setText("LFO", dontSendNotification);
    pwmModeLabel.setFont (Font (9.0f, Font::bold));


    addAndMakeVisible(&manModeLabel);
    
    manModeLabel.setText("MAN", dontSendNotification);
    manModeLabel.setFont (Font (8.0f, Font::bold));
    


    pwmModeVal = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (*processor.tree, "pwmMode", pwmModeSlider);
}

PWMModeSwitch::~PWMModeSwitch()
{
    pwmModeVal = nullptr;
}

void PWMModeSwitch::paint (Graphics& g)
{
  
}

void PWMModeSwitch::resized()
{
  pwmModeLabel.setBounds(0, 47, 30, 30);
  pwmModeSlider.setBounds(3, 70, 20, 30);
  manModeLabel.setBounds(0, 93, 30, 30);
}

void PWMModeSwitch::sliderValueChanged(Slider* slider)
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
