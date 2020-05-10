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
    addAndMakeVisible (sawButton);
    sawVal = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment> (*processor.tree, "sawOsc", sawButton);
    sawButton.addListener(this);
}

SawOscillator::~SawOscillator()
{
    sawVal = nullptr;
}

void SawOscillator::paint (Graphics& g)
{
      g.setColour (getButtonColor(&sawButton));
      g.fillEllipse(12.5, 60,5, 5);
}


void SawOscillator::resized()
{
     sawButton.setBounds (0, 70,buttonSize, buttonSize);
    sawLabel.setBounds (0, 17,buttonSize, buttonSize);
    

}

Colour SawOscillator::getButtonColor(Button* b){
    if(b->getToggleState()){
        return Colour(0xffbe2932);
    }
    else {
        return Colour(0xff5f525d);
    }
}

void SawOscillator::buttonClicked (Button* button) // [2]
{
    repaint();
}
