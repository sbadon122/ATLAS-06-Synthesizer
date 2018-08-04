/*
  ==============================================================================

    Filter.h
    Created: 3 Aug 2018 10:30:42pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Cutoff   : public Component, public Slider::Listener
{
public:
    Cutoff(SynthFrameworkAudioProcessor& p);
    ~Cutoff();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider filterSlider;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Cutoff)
};
