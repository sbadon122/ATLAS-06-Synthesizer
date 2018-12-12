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
    lfoFilterEnvelopeLabel.setText("LFO", dontSendNotification);
    lfoFilterEnvelopeLabel.setFont (Font (12.0f, Font::plain));
    lfoFilterEnvelopeLabel.setJustificationType(Justification::centred);
    lfoFilterEnvelopeVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "lfoFilterEnvelope", lfoFilterEnvelopeSlider);

    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("0", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("5", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("10", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
}

LfoFilterEnvelope::~LfoFilterEnvelope()
{
    lfoFilterEnvelopeVal = nullptr;
}

void LfoFilterEnvelope::paint (Graphics& g)
{

}

void LfoFilterEnvelope::resized()
{
    lfoFilterEnvelopeSlider.setBounds(0, 30, sliderWidth, 100);
    tenLabel1.setBounds(sliderWidth, 37.5, 20, 10);
    fiveLabel1.setBounds(sliderWidth, 77.5, 20, 10);
    zeroLabel1.setBounds(sliderWidth, 114, 20, 10);
}

void LfoFilterEnvelope::sliderValueChanged(Slider* slider)
{
    
}
