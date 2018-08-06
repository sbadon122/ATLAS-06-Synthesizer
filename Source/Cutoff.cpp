/*
  ==============================================================================

    Filter.cpp
    Created: 3 Aug 2018 10:30:42pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Cutoff.h"

//==============================================================================
Cutoff::Cutoff(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    filterSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    filterSlider.setRange(30.0f, 4000.0f);
    filterSlider.setValue(4000.0f);
    filterSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    filterSlider.addListener(this);
    addAndMakeVisible(&filterSlider);
    
    filterVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "cutoff", filterSlider);

}

Cutoff::~Cutoff()
{
}

void Cutoff::paint (Graphics& g)
{
  
}

void Cutoff::resized()
{
    filterSlider.setBounds(10, 10, 40, 100);

}

void Cutoff::sliderValueChanged(Slider* slider)
{
    
}
