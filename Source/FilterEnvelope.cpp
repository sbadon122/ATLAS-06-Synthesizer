/*
  ==============================================================================

    FilterEnvelope.cpp
    Created: 7 Aug 2018 3:47:44pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "FilterEnvelope.h"

//==============================================================================
FilterEnvelope::FilterEnvelope(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    filterEnvelopeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    filterEnvelopeSlider.setRange(30.0f, 4000.0f);
    filterEnvelopeSlider.setValue(30.0f);
    filterEnvelopeSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    filterEnvelopeSlider.addListener(this);
    addAndMakeVisible(&filterEnvelopeSlider);
    addAndMakeVisible(&filterEnvelopeLabel);
    filterEnvelopeLabel.attachToComponent(&filterEnvelopeSlider, false);
    filterEnvelopeLabel.setText("ENV", dontSendNotification);
    filterEnvelopeLabel.setFont (Font (12.0f, Font::plain));
    filterEnvelopeLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("0", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("5", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("10", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
    filterEnvelopeVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "filterEnvelope", filterEnvelopeSlider);
}

FilterEnvelope::~FilterEnvelope()
{
}

void FilterEnvelope::paint (Graphics& g)
{
}

void FilterEnvelope::resized()
{
    tenLabel1.setBounds(0, 37.5, 20, 10);
    fiveLabel1.setBounds(5, 77.5, 20, 10);
    zeroLabel1.setBounds(5, 114, 20, 10);
    filterEnvelopeSlider.setBounds(20, 30, sliderWidth, 100);

}

void FilterEnvelope::sliderValueChanged(Slider* slider)
{
    
}
