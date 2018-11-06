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
class PitchRange    : public Component
{
public:
    PitchRange(SynthFrameworkAudioProcessor& p);
    ~PitchRange();

    void paint (Graphics&) override;
    void resized() override;

private:
    SynthFrameworkAudioProcessor& processor;
    TextButton range4Button    { "4'" };
    Label range4Label         { {}, "4'"};
    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> range4Val;
    
    TextButton range8Button    { "8'" };
    Label range8Label         { {}, "8'"};
    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> range8Val;
    
    TextButton range16Button    { "16'" };
    Label range16Label         { {}, "16'"};
    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> range16Val;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PitchRange)
};
