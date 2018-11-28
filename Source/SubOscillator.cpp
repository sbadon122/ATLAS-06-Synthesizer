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
    subOscLabel.setText("Sub", dontSendNotification);
    subOscLabel.setFont (Font (12.0f, Font::plain));
    subOscLabel.setJustificationType(Justification::centred);
    
    subOscVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "subOsc", subOscSlider);


}

SubOscillator::~SubOscillator()
{
}

void SubOscillator::paint (Graphics& g)
{
    g.fillAll(Colours::grey);
    
}

void SubOscillator::resized()
{
    subOscSlider.setBounds(0, 30, 50, 100);
}

void SubOscillator::sliderValueChanged(Slider* slider)
{
    
}
