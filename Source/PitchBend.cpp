/*
  ==============================================================================

    PitchBend.cpp
    Created: 12 Dec 2018 1:55:59pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PitchBend.h"

//==============================================================================
PitchBend::PitchBend(SynthFrameworkAudioProcessor& p):
processor(p)
{
    pitchBendSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    pitchBendSlider.setRange(-100.0f, 100.0f);
    pitchBendSlider.setValue(0);
    pitchBendSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&pitchBendSlider);
    pitchBendSlider.setLookAndFeel(&pitchBendLookAndFeel);
    pitchBendSlider.addListener(this);
    
    pitchBendVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "pitchBend", pitchBendSlider);
    
    dcoSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    dcoSlider.setRange(0, 12.0f);
    dcoSlider.setValue(0);
    dcoSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    dcoSlider.setLookAndFeel(&sliderLookAndFeel);
    addAndMakeVisible(&dcoSlider);

    
    dcoSliderVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "dcoSliderPitchBend", dcoSlider);
    
    vcfSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    vcfSlider.setRange(0, 10.0f);
    vcfSlider.setValue(0);
    vcfSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    vcfSlider.setLookAndFeel(&sliderLookAndFeel);
    addAndMakeVisible(&vcfSlider);
    
    
    dcoSliderVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "vcfSliderPitchBend", dcoSlider);
    
    addAndMakeVisible(&dcoLabel);
    dcoLabel.setJustificationType(Justification::centred);
    dcoLabel.setFont (Font (8.0f, Font::plain));
    
    addAndMakeVisible(&vcfLabel);
    vcfLabel.setJustificationType(Justification::centred);
    vcfLabel.setFont (Font (8.0f, Font::plain));
}

PitchBend::~PitchBend()
{
    pitchBendVal = nullptr;
    pitchBendSlider.setLookAndFeel(nullptr);
    dcoSlider.setLookAndFeel(nullptr);
}

void PitchBend::paint (Graphics& g)
{
    pitchBendSlider.setBounds(0, 45, 90, 30);
    dcoSlider.setBounds(15, 5, 30, 55);
    vcfSlider.setBounds(45, 5, 30, 55);
    dcoLabel.setBounds(15, 0, 30, 10);
    vcfLabel.setBounds(45, 0, 30, 10);;
}

void PitchBend::resized()
{
  

}

void PitchBend::sliderValueChanged (Slider *slider)
{
    
}

void PitchBend:: sliderDragEnded(Slider *slider){
    slider->setValue(0);
}
