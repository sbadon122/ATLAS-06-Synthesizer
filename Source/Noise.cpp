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
    
    noiseVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "noise", noiseSlider);


}

Noise::~Noise()
{
}

void Noise::paint (Graphics& g)
{
     noiseSlider.setBounds(10, 30, 40, 100);
}

void Noise::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void Noise::sliderValueChanged(Slider* slider)
{
    
}
