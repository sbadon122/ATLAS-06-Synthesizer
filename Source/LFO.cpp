/*
  ==============================================================================

    LFO.cpp
    Created: 12 Aug 2018 8:37:53pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "LFO.h"

//==============================================================================
LFO::LFO(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    lfoRateSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    lfoRateSlider.setRange(0, 100.0f);
    lfoRateSlider.setValue(0);
    lfoRateSlider.setSkewFactor(0.4f);
    lfoRateSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    lfoRateSlider.addListener(this);
    addAndMakeVisible(&lfoRateSlider);
    addAndMakeVisible(&lfoRateLabel);
    lfoRateLabel.attachToComponent(&lfoRateSlider, false);
    lfoRateLabel.setText("LFO Rate", dontSendNotification);
    
    lfoDelaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    lfoDelaySlider.setRange(0.1f, 50000.0f);
    lfoDelaySlider.setValue(0.1f);
    lfoDelaySlider.setSkewFactor(0.4f);
    lfoDelaySlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    lfoDelaySlider.addListener(this);
    addAndMakeVisible(&lfoDelaySlider);
    addAndMakeVisible(&lfoDelayLabel);
    lfoDelayLabel.attachToComponent(&lfoDelaySlider, false);
    lfoDelayLabel.setText("LFO Delay", dontSendNotification);
    
    lfoRateVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "lfoRate", lfoRateSlider);
    lfoDelayVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "lfoDelay", lfoDelaySlider);

}

LFO::~LFO()
{
}

void LFO::paint (Graphics& g)
{
   
}

void LFO::resized()
{
    lfoRateSlider.setBounds(10, 30, 40, 100);
    lfoDelaySlider.setBounds(60, 30, 40, 100);

}

void LFO::sliderValueChanged(Slider* slider)
{
    
}
