/*
  ==============================================================================

    Envelope.cpp
    Created: 3 Aug 2018 9:42:53pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthFrameworkAudioProcessor& p) :
processor(p)
{
        attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        attackSlider.setRange(0.1f, 5000.0f);
        attackSlider.setValue(0.1f);
        attackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        attackSlider.addListener(this);
        addAndMakeVisible(&attackSlider);
    
        decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        decaySlider.setRange(1.0f, 2000.0f);
        decaySlider.setValue(1.0f);
        decaySlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        decaySlider.addListener(this);
        addAndMakeVisible(&decaySlider);
        sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        sustainSlider.setRange(0.0f, 1.0f);
        sustainSlider.setValue(0.8f);
        sustainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        sustainSlider.addListener(this);
        addAndMakeVisible(&sustainSlider);
    
        releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        releaseSlider.setRange(0.1f, 5000.0f);
        releaseSlider.setValue(0.8f);
        releaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        releaseSlider.addListener(this);
        addAndMakeVisible(&releaseSlider);
    
        //sends value of the sliders to the tree state in the processor
        attackVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "attack", attackSlider);
        decayVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "decay", decaySlider);
        sustainVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "sustain", sustainSlider);
        releaseVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "release", releaseSlider);

}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
   
}

void Envelope::resized()
{
    attackSlider.setBounds(10, 10, 40, 100);
    decaySlider.setBounds(60, 10, 40, 100);
    sustainSlider.setBounds(110, 10, 40, 100);
    releaseSlider.setBounds(160, 10, 40, 100);
   
    

}

void Envelope::sliderValueChanged (Slider *slider)
{
    
}

