/*
  ==============================================================================

    Oscillator.cpp
    Created: 3 Aug 2018 1:40:26pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(SynthFrameworkAudioProcessor& p) :
processor(p)
{

    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Square", 3);
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);
    
    oscMenu.setJustificationType(Justification::centred);
    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(*processor.tree, "wavetype", oscMenu);
    

}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
   
}

void Oscillator::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    oscMenu.setBounds(area.removeFromTop(20));

}

void Oscillator::comboBoxChanged(ComboBox* box)
{
    
}
