/*
  ==============================================================================

    LFOPitch.h
    Created: 5 Sep 2018 3:23:54pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class LFOPitch    : public Component, public Slider::Listener
{
public:
    LFOPitch(SynthFrameworkAudioProcessor& p);
    ~LFOPitch();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider lfoPitchSlider;
    Label lfoPitchLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> lfoPitchVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LFOPitch)
};
