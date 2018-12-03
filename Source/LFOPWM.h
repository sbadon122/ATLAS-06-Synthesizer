/*
  ==============================================================================

    LFOPWM.h
    Created: 5 Sep 2018 4:22:56pm
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
class LFOPWM    : public Component, public Slider::Listener
{
public:
    LFOPWM(SynthFrameworkAudioProcessor& p);
    ~LFOPWM();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider lfoPwmSlider;
    Label lfoPwmLabel;
    Label zeroLabel1;
    Label fiveLabel1;
    Label tenLabel1;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> lfoPwmVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LFOPWM)
};
