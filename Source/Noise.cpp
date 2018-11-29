/*
  ==============================================================================

    Noise.cpp
    Created: 2 Sep 2018 11:06:24pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Noise.h"

//==============================================================================
Noise::Noise(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    noiseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    noiseSlider.setRange(0, 1);
    noiseSlider.setValue(0);
    noiseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    noiseSlider.addListener(this);
    addAndMakeVisible(&noiseSlider);
    addAndMakeVisible(&noiseLabel);
    noiseLabel.attachToComponent(&noiseSlider, false);
    noiseLabel.setText("Noise", dontSendNotification);
    noiseLabel.setFont (Font (12.0f, Font::plain));
    noiseLabel.setJustificationType(Justification::centred);
    
    noiseVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "noise", noiseSlider);


}

Noise::~Noise()
{
}

void Noise::paint (Graphics& g)
{
    
}

void Noise::resized()
{
    noiseSlider.setBounds(0, 30, 50, 100);
}

void Noise::sliderValueChanged(Slider* slider)
{
    
}
