/*
  ==============================================================================

    PolaritySwitch.h
    Created: 5 Dec 2018 3:33:10pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class PolaritySwitch    : public Component, public Slider::Listener
{
public:
    PolaritySwitch(SynthFrameworkAudioProcessor& p);
    ~PolaritySwitch();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> polarityModeVal;
    Slider polarityModeSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PolaritySwitch)
};
