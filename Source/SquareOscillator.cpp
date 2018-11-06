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
    squareLabel.attachToComponent(&squareButton, false);
    squareLabel.setText("Square", dontSendNotification);
    squareLabel.setFont (Font (12.0f, Font::plain));
    squareLabel.setJustificationType(Justification::centred);
    sawVal = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "squareOsc", squareButton);

}

SquareOscillator::~SquareOscillator()
{
}

void SquareOscillator::paint (Graphics& g)
{
    g.fillAll(Colours::grey);
  
}

void SquareOscillator::resized()
{
     squareButton.setBounds (5, 60,40, 40);
}
