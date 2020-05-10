/*
  ==============================================================================

    SubOscillator.h
    Created: 3 Sep 2018 11:51:05am
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
class SubOscillator    : public Component, public Slider::Listener
{
public:
    SubOscillator(SynthFrameworkAudioProcessor& p);
    ~SubOscillator();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider subOscSlider;
    Label subOscLabel;
    Label zeroLabel1;
    Label fiveLabel1;
    Label tenLabel1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> subOscVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SubOscillator)
};
