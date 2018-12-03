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
    squareButton.addListener(this);

}

SquareOscillator::~SquareOscillator()
{
}

void SquareOscillator::paint (Graphics& g)
{
    g.setColour (getButtonColor(&squareButton));
    g.fillEllipse(12.5, 60,5, 5);
  
}

void SquareOscillator::resized()
{
     squareButton.setBounds (0, 70,buttonSize, buttonSize);
     squareLabel.setBounds (0, 17,buttonSize, buttonSize);
}

Colour SquareOscillator::getButtonColor(Button* b){
    if(b->getToggleState()){
        return Colour(0xffbe2932);
    }
    else {
        return Colour(0xff5f525d);
    }
}

void SquareOscillator::buttonClicked (Button* button) // [2]
{
    repaint();
}
