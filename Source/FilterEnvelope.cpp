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
    filterEnvelopeLabel.setText("Filter Envelope", dontSendNotification);
    
    resonanceVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "filterEnvelope", filterEnvelopeSlider);
}

FilterEnvelope::~FilterEnvelope()
{
}

void FilterEnvelope::paint (Graphics& g)
{
   
}

void FilterEnvelope::resized()
{
     filterEnvelopeSlider.setBounds(10, 30, 40, 100);

}

void FilterEnvelope::sliderValueChanged(Slider* slider)
{
    
}
