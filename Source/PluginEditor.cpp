/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGui(p), envGui(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 200);
    addAndMakeVisible(&oscGui);
    addAndMakeVisible(&envGui);
    
    //slider initialization values
//    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
//    attackSlider.setRange(0.1f, 5000.0f);
//    attackSlider.setValue(0.1f);
//    attackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
//    attackSlider.addListener(this);
//    addAndMakeVisible(&attackSlider);
//
//    decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
//    decaySlider.setRange(1.0f, 2000.0f);
//    decaySlider.setValue(1.0f);
//    decaySlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
//    decaySlider.addListener(this);
//    addAndMakeVisible(&decaySlider);
//    sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
//    sustainSlider.setRange(0.0f, 1.0f);
//    sustainSlider.setValue(0.8f);
//    sustainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
//    sustainSlider.addListener(this);
//    addAndMakeVisible(&sustainSlider);
//
//    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
//    releaseSlider.setRange(0.1f, 5000.0f);
//    releaseSlider.setValue(0.8f);
//    releaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
//    releaseSlider.addListener(this);
//    addAndMakeVisible(&releaseSlider);
//
//    //sends value of the sliders to the tree state in the processor
//    attackVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "attack", attackSlider);
//    decayVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "decay", decaySlider);
//    sustainVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "sustain", sustainSlider);
//    releaseVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "release", releaseSlider);
    
    
    
}


SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::black);
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    const int componentWidth = 200;
    const int componentHeight = 200;
    Rectangle<int> area = getLocalBounds();
    oscGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    envGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    
}

void SynthFrameworkAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
 
    
}

