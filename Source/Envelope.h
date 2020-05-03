/*
  ==============================================================================

    Envelope.h
    Created: 3 Aug 2018 9:42:53pm
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
class Envelope    : public Component, public Slider::Listener
{
public:
    Envelope(SynthFrameworkAudioProcessor& p);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;

private:
    SynthFrameworkAudioProcessor& processor;
    Slider attackSlider;
    Slider decaySlider;
    Slider sustainSlider;
    Slider releaseSlider;
    Label attackLabel         { {}, "A"};
    Label decayLabel         { {}, "D"};
    Label sustainLabel         { {}, "S"};
    Label releaseLabel         { {}, "R"};
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> attackVal;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> decayVal;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sustainVal;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> releaseVal;
    Label zeroLabel1;
    Label fiveLabel1;
    Label tenLabel1;
    Label zeroLabel2;
    Label fiveLabel2;
    Label tenLabel2;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
