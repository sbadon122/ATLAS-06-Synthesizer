/*
  ==============================================================================

    Pulse.h
    Created: 3 Sep 2018 9:32:00pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Constants.h"

//==============================================================================
/*
*/
class PWM    : public Component, public Slider::Listener
{
public:
    PWM(SynthFrameworkAudioProcessor& p);
    ~PWM();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider pwmSlider;
    Label pwmLabel;
    Label zeroLabel1;
    Label fiveLabel1;
    Label tenLabel1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> pwmVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PWM)
};
