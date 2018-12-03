/*
  ==============================================================================

    PWMModeSwitch.h
    Created: 1 Dec 2018 1:50:56pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class PWMModeSwitch    : public Component, public Slider::Listener
{
public:
    PWMModeSwitch(SynthFrameworkAudioProcessor& p);
    ~PWMModeSwitch();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> pwmModeVal;
    Slider pwmModeSlider;
    Label pwmModeLabel;
    Label manModeLabel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PWMModeSwitch)
};
