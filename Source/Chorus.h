/*
  ==============================================================================

    Chorus.h
    Created: 5 Sep 2018 6:23:33pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Chorus    : public Component
{
public:
    Chorus(SynthFrameworkAudioProcessor& p);
    ~Chorus();

    void paint (Graphics&) override;
    void resized() override;

private:
    SynthFrameworkAudioProcessor& processor;
    TextButton chorus1Button    { "" };
    Label chorus1Label         { {}, "Chorus 1"};
    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> chorus1Val;
    
    TextButton chorus2Button    { "" };
    Label chorus2Label         { {}, "Chorus 2"};
    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> chorus2Val;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Chorus)
};
