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
    sawLabel.attachToComponent(&sawButton, false);
    sawLabel.setText("Saw", dontSendNotification);
    sawLabel.setFont (Font (12.0f, Font::plain));
    sawLabel.setJustificationType(Justification::centred);
    sawVal = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "sawOsc", sawButton);
}

SawOscillator::~SawOscillator()
{
}

void SawOscillator::paint (Graphics& g)
{
      g.fillAll(Colours::grey);
}


void SawOscillator::resized()
{
     sawButton.setBounds (5, 60,40, 40);

}
