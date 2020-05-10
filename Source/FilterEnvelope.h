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
#include "Constants.h"

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
    Label zeroLabel1;
    Label fiveLabel1;
    Label tenLabel1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> filterEnvelopeVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterEnvelope)
};
