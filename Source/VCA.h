/*
  ==============================================================================

    VCA.h
    Created: 2 Sep 2018 9:59:37pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class VCA    : public Component, public Slider::Listener
{
public:
    VCA(SynthFrameworkAudioProcessor& p);
    ~VCA();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider vcaSlider;
    Label vcaLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> vcaVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VCA)
};
