/*
  ==============================================================================

    FilterEnvelope.h
    Created: 7 Aug 2018 3:47:44pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class FilterEnvelope    : public Component, public Slider::Listener
{
public:
    FilterEnvelope(SynthFrameworkAudioProcessor& p);
    ~FilterEnvelope();

    void paint (Graphics&) override;
    void resized() override;
     void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider filterEnvelopeSlider;
    Label filterEnvelopeLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> resonanceVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterEnvelope)
};
