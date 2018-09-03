/*
  ==============================================================================

    SawOscillator.h
    Created: 2 Sep 2018 11:48:13pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class SawOscillator    : public Component
{
public:
    SawOscillator(SynthFrameworkAudioProcessor& p);
    ~SawOscillator();

    void paint (Graphics&) override;
    void resized() override;

private:
    SynthFrameworkAudioProcessor& processor;
    TextButton sawButton    { "sawOsc" };
    Label sawLabel         { {}, "Saw"};
    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> sawVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SawOscillator)
};