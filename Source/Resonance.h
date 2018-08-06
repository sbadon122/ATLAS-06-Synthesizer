/*
  ==============================================================================

    Resonance.h
    Created: 4 Aug 2018 3:56:28pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Resonance    : public Component, public Slider::Listener
{
public:
    Resonance(SynthFrameworkAudioProcessor& p);
    ~Resonance();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider resonanceSlider;
    Label resonanceLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> resonanceVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Resonance)
};
