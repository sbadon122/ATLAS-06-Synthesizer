/*
  ==============================================================================

    Envelope.cpp
    Created: 3 Aug 2018 9:42:53pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthFrameworkAudioProcessor& p) :
processor(p)
{
        attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        attackSlider.setRange(0.1f, 5000.0f);
        attackSlider.setValue(0.1f);
        attackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        attackSlider.addListener(this);
        addAndMakeVisible(&attackSlider);
        addAndMakeVisible(&attackLabel);
        attackLabel.attachToComponent(&attackSlider, false);
        attackLabel.setText("A", dontSendNotification);
        attackLabel.setJustificationType(Justification::centred);
        attackLabel.setFont (Font (12.0f, Font::plain));
    
        decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        decaySlider.setRange(1.0f, 2000.0f);
        decaySlider.setValue(1.0f);
        decaySlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        decaySlider.addListener(this);
        addAndMakeVisible(&decaySlider);
        addAndMakeVisible(&decayLabel);
        decayLabel.attachToComponent(&decaySlider, false);
        decayLabel.setText("D", dontSendNotification);
        decayLabel.setJustificationType(Justification::centred);
        decayLabel.setFont (Font (12.0f, Font::plain));
    
        sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        sustainSlider.setRange(0.0f, 1.0f);
        sustainSlider.setValue(0.8f);
        sustainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        sustainSlider.addListener(this);
        addAndMakeVisible(&sustainSlider);
        addAndMakeVisible(&sustainLabel);
        sustainLabel.attachToComponent(&sustainSlider, false);
        sustainLabel.setText("S", dontSendNotification);
        sustainLabel.setJustificationType(Justification::centred);
        sustainLabel.setFont (Font (12.0f, Font::plain));
    
        releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        releaseSlider.setRange(0.1f, 5000.0f);
        releaseSlider.setValue(5.0f);
        releaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        releaseSlider.addListener(this);
        addAndMakeVisible(&releaseSlider);
        addAndMakeVisible(&releaseLabel);
        releaseLabel.attachToComponent(&releaseSlider, false);
        releaseLabel.setText("R", dontSendNotification);
        releaseLabel.setJustificationType(Justification::centred);
        releaseLabel.setFont (Font (12.0f, Font::plain));
    
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

    
        //sends value of the sliders to the tree state in the processor
        attackVal = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (*processor.tree, "attack", attackSlider);
        decayVal = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (*processor.tree, "decay", decaySlider);
        sustainVal = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (*processor.tree, "sustain", sustainSlider);
        releaseVal = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (*processor.tree, "release", releaseSlider);

}

Envelope::~Envelope()
{
    attackVal = nullptr;
    decayVal = nullptr;
    sustainVal = nullptr;
    releaseVal = nullptr;
}

void Envelope::paint (Graphics& g)
{
}

void Envelope::resized()
{
    tenLabel1.setBounds(0, 37.5, 20, 10);
    fiveLabel1.setBounds(5, 77.5, 20, 10);
    zeroLabel1.setBounds(5, 114, 20, 10);
    attackSlider.setBounds(20, 30, sliderWidth, 100);
    decaySlider.setBounds(60, 30, sliderWidth, 100);
    sustainSlider.setBounds(100, 30, sliderWidth, 100);
    releaseSlider.setBounds(140, 30, sliderWidth, 100);
    
    tenLabel2.setBounds(sliderWidth*4+20, 37.5, 20, 10);
    fiveLabel2.setBounds(sliderWidth*4+20, 77.5, 20, 10);
    zeroLabel2.setBounds(sliderWidth*4+20, 114, 20, 10);

}

void Envelope::sliderValueChanged (Slider *slider)
{
    
}

