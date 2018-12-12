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
    resonanceLabel.setText("RES", dontSendNotification);
    resonanceLabel.setFont (Font (12.0f, Font::plain));
    resonanceLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("0", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("5", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("10", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
    resonanceVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "resonance", resonanceSlider);

}

Resonance::~Resonance()
{
    resonanceVal = nullptr;
}

void Resonance::paint (Graphics& g)
{
}

void Resonance::resized()
{
    
    resonanceSlider.setBounds(0, 30, sliderWidth, 100);
    tenLabel1.setBounds(sliderWidth, 37.5, 20, 10);
    fiveLabel1.setBounds(sliderWidth, 77.5, 20, 10);
    zeroLabel1.setBounds(sliderWidth, 114, 20, 10);
}

void Resonance::sliderValueChanged(Slider* slider)
{
    
}

