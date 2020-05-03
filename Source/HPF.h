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
#include "Constants.h"

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
    Label zeroLabel1;
    Label fiveLabel1;
    Label tenLabel1;
    Label zeroLabel2;
    Label fiveLabel2;
    Label tenLabel2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> hfpVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HPF)
};
