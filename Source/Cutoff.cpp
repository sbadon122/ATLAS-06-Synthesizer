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
    addAndMakeVisible(&filterLabel);
    filterLabel.attachToComponent(&filterSlider, false);
    filterLabel.setText("FREQ", dontSendNotification);
    filterLabel.setFont (Font (12.0f, Font::plain));
    filterLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("0", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("5", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("10", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
    filterVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "cutoff", filterSlider);

}

Cutoff::~Cutoff()
{
    filterVal = nullptr;
}

void Cutoff::paint (Graphics& g)
{
   
}

void Cutoff::resized()
{
    tenLabel1.setBounds(0, 37.5, 20, 10);
    fiveLabel1.setBounds(5, 77.5, 20, 10);
    zeroLabel1.setBounds(5, 114, 20, 10);
    filterSlider.setBounds(20, 30, sliderWidth, 100);

}

void Cutoff::sliderValueChanged(Slider* slider)
{
    
}
