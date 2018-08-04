/*
  ==============================================================================

    Oscillator.h
    Created: 3 Aug 2018 1:40:26pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Oscillator    : public Component,
private ComboBox::Listener
{
public:
    Oscillator(SynthFrameworkAudioProcessor& p);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;
    void comboBoxChanged(ComboBox*) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    ComboBox oscMenu;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
