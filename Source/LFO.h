/*
  ==============================================================================

    LFO.h
    Created: 12 Aug 2018 8:37:53pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class LFO    : public Component, public Slider::Listener
{
public:
    LFO(SynthFrameworkAudioProcessor& p);
    ~LFO();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider lfoRateSlider;
    Label lfoRateLabel;
    Slider lfoDelaySlider;
    Label lfoDelayLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> lfoRateVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> lfoDelayVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LFO)
};
