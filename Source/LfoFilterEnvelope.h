/*
  ==============================================================================

    LfoFilterEnvelope.h
    Created: 14 Aug 2018 10:10:16pm
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
class LfoFilterEnvelope    : public Component, public Slider::Listener
{
public:
    LfoFilterEnvelope(SynthFrameworkAudioProcessor& p);
    ~LfoFilterEnvelope();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider lfoFilterEnvelopeSlider;
    Label lfoFilterEnvelopeLabel;
    Label zeroLabel1;
    Label fiveLabel1;
    Label tenLabel1;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> lfoFilterEnvelopeVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LfoFilterEnvelope)
};
