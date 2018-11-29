/*
  ==============================================================================

    Resonance.cpp
    Created: 4 Aug 2018 3:56:28pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Resonance.h"

//==============================================================================
Resonance::Resonance(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    resonanceSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    resonanceSlider.setRange(1.0f, 20.0f);
    resonanceSlider.setValue(1.0f);
    resonanceSlider.setTextBoxStyle(Slider::TextBoxAbove, true, 0, 0);
    resonanceSlider.addListener(this);
    addAndMakeVisible(&resonanceSlider);
    resonanceLabel.attachToComponent(&resonanceSlider, false);
    resonanceLabel.setText("Resonance", dontSendNotification);
    resonanceLabel.setFont (Font (12.0f, Font::plain));
    resonanceLabel.setJustificationType(Justification::centred);
    
    resonanceVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "resonance", resonanceSlider);

}

Resonance::~Resonance()
{
}

void Resonance::paint (Graphics& g)
{
}

void Resonance::resized()
{
    resonanceSlider.setBounds(0, 30, 50, 100);
}

void Resonance::sliderValueChanged(Slider* slider)
{
    
}

