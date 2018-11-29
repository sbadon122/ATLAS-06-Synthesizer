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
    squareLabel.setText("Square", dontSendNotification);
    squareLabel.setFont (Font (12.0f, Font::plain));
    squareLabel.setJustificationType(Justification::centred);
    sawVal = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "squareOsc", squareButton);
    squareButton.addListener(this);

}

SquareOscillator::~SquareOscillator()
{
}

void SquareOscillator::paint (Graphics& g)
{
    g.setColour (getButtonColor(&squareButton));
    g.fillEllipse(17.5, 50,5, 5);
  
}

void SquareOscillator::resized()
{
     squareButton.setBounds (0, 60,40, 40);
     squareLabel.setBounds (0, 17,40, 40);
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
