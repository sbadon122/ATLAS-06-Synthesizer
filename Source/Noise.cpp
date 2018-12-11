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
    noiseLabel.setText("NOISE", dontSendNotification);
    noiseLabel.setFont (Font (12.0f, Font::plain));
    noiseLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("0", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("5", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("10", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
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
    noiseSlider.setBounds(0, 30, sliderWidth, 100);
    tenLabel1.setBounds(sliderWidth, 37.5, 20, 10);
    fiveLabel1.setBounds(sliderWidth, 77.5, 20, 10);
    zeroLabel1.setBounds(sliderWidth, 114, 20, 10);
}

void Noise::sliderValueChanged(Slider* slider)
{
    
}
