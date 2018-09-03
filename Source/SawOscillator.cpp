/*
  ==============================================================================

    SawOscillator.cpp
    Created: 2 Sep 2018 11:48:13pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SawOscillator.h"

//==============================================================================
SawOscillator::SawOscillator(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    sawButton.setClickingTogglesState (true);
    addAndMakeVisible (sawLabel);
    addAndMakeVisible (sawButton);
    sawVal = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "sawOsc", sawButton);
}

SawOscillator::~SawOscillator()
{
}

void SawOscillator::paint (Graphics& g)
{
    sawButton.setBounds (10, 10, 90, 50);
}


void SawOscillator::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
