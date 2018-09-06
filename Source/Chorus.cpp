/*
  ==============================================================================

    Chorus.cpp
    Created: 5 Sep 2018 6:23:33pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Chorus.h"

//==============================================================================
Chorus::Chorus(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    chorus1Button.setClickingTogglesState (true);
    addAndMakeVisible (chorus1Label);
    addAndMakeVisible (chorus1Button);
    chorus1Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "chorus1", chorus1Button);
    
    chorus2Button.setClickingTogglesState (true);
    addAndMakeVisible (chorus2Label);
    addAndMakeVisible (chorus2Button);
    chorus2Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "chorus2", chorus2Button);

}

Chorus::~Chorus()
{
}

void Chorus::paint (Graphics& g)
{
   chorus1Button.setBounds (0, 10,100, 50);
   chorus2Button.setBounds (110, 10, 100, 50);
    
}

void Chorus::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
