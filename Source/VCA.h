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
#include "Constants.h"
#include "SliderLookAndFeel.h"

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
    
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> ampModeVal;
    Slider ampModeSlider;
    Label ampLabel;
    Label gateLabel;
    Label zeroLabel1;
    Label fiveLabel1;
    Label tenLabel1;
    Label zeroLabel2;
    Label fiveLabel2;
    Label tenLabel2;
    SliderToggleLookAndFeel sliderToggleLookAndFeel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VCA)
};
