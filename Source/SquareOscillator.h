/*
  ==============================================================================

    SquareOscillator.h
    Created: 3 Sep 2018 11:24:55am
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
class SquareOscillator    : public Component,
                            public Button::Listener
{
public:
    SquareOscillator(SynthFrameworkAudioProcessor& p);
    ~SquareOscillator();

    void paint (Graphics&) override;
    void resized() override;
    Colour getButtonColor(Button* b);
    void buttonClicked (Button* button) override; 

private:
    SynthFrameworkAudioProcessor& processor;
    TextButton squareButton    { "" };
    Label squareLabel         { {}, ""};
    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> sawVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SquareOscillator)
};
