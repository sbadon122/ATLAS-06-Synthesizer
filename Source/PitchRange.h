/*
  ==============================================================================

    Range.h
    Created: 3 Sep 2018 8:46:48pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class PitchRange    : public Component,
private ComboBox::Listener
{
public:
    PitchRange(SynthFrameworkAudioProcessor& p);
    ~PitchRange();

    void paint (Graphics&) override;
    void resized() override;
    void comboBoxChanged(ComboBox*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> rangeSelection;
    ComboBox rangeMenu;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PitchRange)
};
