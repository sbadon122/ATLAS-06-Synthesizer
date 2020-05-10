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
#include "Constants.h"

//==============================================================================
/*
*/
class SawOscillator    : public Component,
                         public Button::Listener
{
public:
    SawOscillator(SynthFrameworkAudioProcessor& p);
    ~SawOscillator();

    void paint (Graphics&) override;
    void resized() override;
    Colour getButtonColor(Button* b);
    void buttonClicked (Button* button) override; 

private:
    SynthFrameworkAudioProcessor& processor;
    TextButton sawButton    { "" };
    Label sawLabel         { {}, ""};
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> sawVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SawOscillator)
};
