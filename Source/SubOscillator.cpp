/*
  ==============================================================================

    SubOscillator.cpp
    Created: 3 Sep 2018 11:51:05am
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SubOscillator.h"

//==============================================================================
SubOscillator::SubOscillator(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    subOscSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    subOscSlider.setRange(0, 1);
    subOscSlider.setValue(0);
    subOscSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    subOscSlider.addListener(this);
    addAndMakeVisible(&subOscSlider);
    addAndMakeVisible(&subOscLabel);
    subOscLabel.attachToComponent(&subOscSlider, false);
    subOscLabel.setText("SUB", dontSendNotification);
    subOscLabel.setFont (Font (12.0f, Font::plain));
    subOscLabel.setJustificationType(Justification::centred);
    
    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("0", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("5", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("10", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
    subOscVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "subOsc", subOscSlider);


}

SubOscillator::~SubOscillator()
{
}

void SubOscillator::paint (Graphics& g)
{

    
}

void SubOscillator::resized()
{
    tenLabel1.setBounds(0, 37.5, 20, 10);
    fiveLabel1.setBounds(5, 77.5, 20, 10);
    zeroLabel1.setBounds(5, 114, 20, 10);
    subOscSlider.setBounds(20, 30, sliderWidth, 100);
}

void SubOscillator::sliderValueChanged(Slider* slider)
{
    
}
