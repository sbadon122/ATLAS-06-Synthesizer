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
    filterEnvelopeLabel.setText("Envelope", dontSendNotification);
    filterEnvelopeLabel.setFont (Font (12.0f, Font::plain));
    filterEnvelopeLabel.setJustificationType(Justification::centred);
    
    filterEnvelopeVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "filterEnvelope", filterEnvelopeSlider);
}

FilterEnvelope::~FilterEnvelope()
{
}

void FilterEnvelope::paint (Graphics& g)
{
     g.fillAll(Colours::grey);
}

void FilterEnvelope::resized()
{
     filterEnvelopeSlider.setBounds(0, 30, 50, 100);

}

void FilterEnvelope::sliderValueChanged(Slider* slider)
{
    
}
