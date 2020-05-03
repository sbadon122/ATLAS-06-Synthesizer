/*
  ==============================================================================

    LFOPitch.cpp
    Created: 5 Sep 2018 3:23:54pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "LFOPitch.h"

//==============================================================================
LFOPitch::LFOPitch(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    lfoPitchSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    lfoPitchSlider.setRange(0, 1.0f);
    lfoPitchSlider.setValue(0);
    lfoPitchSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    lfoPitchSlider.addListener(this);
    addAndMakeVisible(&lfoPitchSlider);
    addAndMakeVisible(&lfoPitchLabel);
    lfoPitchLabel.attachToComponent(&lfoPitchSlider, false);
    lfoPitchLabel.setText("LFO Pitch", dontSendNotification);
    
    lfoPitchVal = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (*processor.tree, "lfoPitch", lfoPitchSlider);
}

LFOPitch::~LFOPitch()
{
}

void LFOPitch::paint (Graphics& g)
{
    lfoPitchSlider.setBounds(50, 30, 80, 100);
}

void LFOPitch::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void LFOPitch::sliderValueChanged(Slider* slider)
{
    
}
