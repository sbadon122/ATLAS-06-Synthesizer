/*
  ==============================================================================

    HPF.h
    Created: 2 Sep 2018 5:18:05pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class HPF    : public Component, public Slider::Listener
{
public:
    HPF(SynthFrameworkAudioProcessor& p);
    ~HPF();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider hpfSlider;
    Label hpfLabel;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> hfpVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HPF)
};
