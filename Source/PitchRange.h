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
#include "Constants.h"

//==============================================================================
/*
*/
class PitchRange    : public Component,
                      public Button::Listener
{
public:
    PitchRange(SynthFrameworkAudioProcessor& p);
    ~PitchRange();

    void paint (Graphics&) override;
    void resized() override;
    void buttonClicked (Button* button) override; // [2]
    Colour getButtonColor(Button* button);
   

private:
    SynthFrameworkAudioProcessor& processor;
    TextButton range4Button    { "" };
    Label range4Label         { {}, "4'"};
    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> range4Val;
    
    TextButton range8Button    { "" };
    Label range8Label         { {}, "8'"};
    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> range8Val;
    
    TextButton range16Button    { "" };
    Label range16Label         { {}, "16'"};
    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> range16Val;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PitchRange)
};
