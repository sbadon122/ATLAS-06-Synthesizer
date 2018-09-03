/*
  ==============================================================================

    Noise.h
    Created: 2 Sep 2018 11:06:24pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Noise    : public Component, public Slider::Listener
{
public:
    Noise(SynthFrameworkAudioProcessor& p);
    ~Noise();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider noiseSlider;
    Label noiseLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> noiseVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Noise)
};
