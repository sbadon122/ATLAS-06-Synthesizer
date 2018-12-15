/*
  ==============================================================================

    PitchBend.h
    Created: 12 Dec 2018 1:55:59pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SliderLookAndFeel.h"

//==============================================================================
/*
*/
class PitchBend    : public Component, public Slider::Listener
{
public:
    PitchBend(SynthFrameworkAudioProcessor& p);
    ~PitchBend();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;
    void sliderDragEnded (Slider*) override;


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PitchBend)
    SynthFrameworkAudioProcessor& processor;
    Slider pitchBendSlider;
    Slider dcoSlider;
    Slider vcfSlider;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> pitchBendVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> dcoSliderVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> vcfSliderVal;
    PitchBendLookAndFeel pitchBendLookAndFeel;
    SliderPitchBendLookAndFeel sliderLookAndFeel;
    Label dcoLabel         { {}, "DCO"};
    Label vcfLabel         { {}, "VCF"};
};
