/*
  ==============================================================================

    SquareOscillator.cpp
    Created: 3 Sep 2018 11:24:55am
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SquareOscillator.h"

//==============================================================================
SquareOscillator::SquareOscillator(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    squareButton.setClickingTogglesState (true);
    addAndMakeVisible (squareLabel);
    addAndMakeVisible (squareButton);
    sawVal = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "squareOsc", squareButton);

}

SquareOscillator::~SquareOscillator()
{
}

void SquareOscillator::paint (Graphics& g)
{
   squareButton.setBounds (10, 10, 90, 50);
}

void SquareOscillator::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
