/*
  ==============================================================================

    LfoFilterEnvelope.cpp
    Created: 14 Aug 2018 10:10:16pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "LfoFilterEnvelope.h"

//==============================================================================
LfoFilterEnvelope::LfoFilterEnvelope(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    lfoFilterEnvelopeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    lfoFilterEnvelopeSlider.setRange(30.0f, 4000.0f);
    lfoFilterEnvelopeSlider.setValue(30.0f);
    lfoFilterEnvelopeSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    lfoFilterEnvelopeSlider.addListener(this);
    addAndMakeVisible(&lfoFilterEnvelopeSlider);
    addAndMakeVisible(&lfoFilterEnvelopeLabel);
    lfoFilterEnvelopeLabel.attachToComponent(&lfoFilterEnvelopeSlider, false);
    lfoFilterEnvelopeLabel.setText("LFO Filter Envelope", dontSendNotification);
    
    lfoFilterEnvelopeVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "lfoFilterEnvelope", lfoFilterEnvelopeSlider);

}

LfoFilterEnvelope::~LfoFilterEnvelope()
{
}

void LfoFilterEnvelope::paint (Graphics& g)
{
  
}

void LfoFilterEnvelope::resized()
{
    lfoFilterEnvelopeSlider.setBounds(10, 30, 40, 100);
}

void LfoFilterEnvelope::sliderValueChanged(Slider* slider)
{
    
}
