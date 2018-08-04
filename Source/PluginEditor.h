/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Envelope.h"

//==============================================================================
/**
*/
class SynthFrameworkAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor&);
    ~SynthFrameworkAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (Slider* slider);
    

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;
    
    Oscillator oscGui;
    Envelope envGui;
    
//    Slider attackSlider;
//    Slider decaySlider;
//    Slider sustainSlider;
//    Slider releaseSlider;
//    
//    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> attackVal;
//    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> decayVal;
//    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sustainVal;
//    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> releaseVal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthFrameworkAudioProcessorEditor)
};
