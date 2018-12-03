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
    lfoRateSlider.setRange(0, 10.0f);
    lfoRateSlider.setValue(0);
    lfoRateSlider.setSkewFactorFromMidPoint(5.0f);
    lfoRateSlider.setTextBoxStyle(Slider::TextBoxAbove, true, 0, 0);
    lfoRateSlider.addListener(this);
    addAndMakeVisible(&lfoRateSlider);
    addAndMakeVisible(&lfoRateLabel);
    lfoRateLabel.attachToComponent(&lfoRateSlider, false);
    lfoRateLabel.setText("LFO", dontSendNotification);
    lfoRateLabel.setJustificationType(Justification::centred);
    lfoRateLabel.setFont (Font (12.0f, Font::plain));
    
    lfoDelaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    lfoDelaySlider.setRange(0.1f, 50000.0f);
    lfoDelaySlider.setValue(0.1f);
    lfoDelaySlider.setSkewFactor(0.4f);
    lfoDelaySlider.setTextBoxStyle(Slider::TextBoxAbove, true, 0, 0);
    lfoDelaySlider.addListener(this);
    addAndMakeVisible(&lfoDelaySlider);
    addAndMakeVisible(&lfoDelayLabel);
    lfoDelayLabel.attachToComponent(&lfoDelaySlider, false);
    lfoDelayLabel.setText("Delay", dontSendNotification);
    lfoDelayLabel.setJustificationType(Justification::centred);
    lfoDelayLabel.setFont (Font (12.0f, Font::plain));
    
    lfoRateVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "lfoRate", lfoRateSlider);
    lfoDelayVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "lfoDelay", lfoDelaySlider);
    
    addAndMakeVisible(&zeroLabel1);
    zeroLabel1.setText("0", dontSendNotification);
    zeroLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel1);
    fiveLabel1.setText("5", dontSendNotification);
    fiveLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel1);
    tenLabel1.setText("10", dontSendNotification);
    tenLabel1.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&zeroLabel2);
    zeroLabel2.setText("0", dontSendNotification);
    zeroLabel2.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&fiveLabel2);
    fiveLabel2.setText("5", dontSendNotification);
    fiveLabel2.setFont (Font (numberFontSize, Font::bold));
    
    addAndMakeVisible(&tenLabel2);
    tenLabel2.setText("10", dontSendNotification);
    tenLabel2.setFont (Font (numberFontSize, Font::bold));

}

LFO::~LFO()
{
}

void LFO::paint (Graphics& g)
{
}

void LFO::resized()
{
    tenLabel1.setBounds(0, 37.5, 20, 10);
    fiveLabel1.setBounds(5, 77.5, 20, 10);
    zeroLabel1.setBounds(5, 114, 20, 10);
    lfoRateSlider.setBounds(20, 30, sliderWidth, 100);
    lfoDelaySlider.setBounds(60, 30, sliderWidth, 100);
    tenLabel2.setBounds(sliderWidth * 2 + 20, 37.5, 20, 10);
    fiveLabel2.setBounds(sliderWidth * 2 + 20, 77.5, 20, 10);
    zeroLabel2.setBounds(sliderWidth * 2 + 20, 114, 20, 10);

}

void LFO::sliderValueChanged(Slider* slider)
{
    
}
