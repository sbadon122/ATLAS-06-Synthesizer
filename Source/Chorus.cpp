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
    chorus1Label.attachToComponent(&chorus1Button, false);
    chorus1Label.setText("i", dontSendNotification);
    chorus1Label.setFont (Font (12.0f, Font::plain));
    chorus1Label.setJustificationType(Justification::centred);
    chorus1Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "chorus1", chorus1Button);
    
    chorus2Button.setClickingTogglesState (true);
    addAndMakeVisible (chorus2Label);
    addAndMakeVisible (chorus2Button);
    chorus2Label.attachToComponent(&chorus2Button, false);
    chorus2Label.setText("ii", dontSendNotification);
    chorus2Label.setFont (Font (12.0f, Font::plain));
    chorus2Label.setJustificationType(Justification::centred);
    chorus2Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "chorus2", chorus2Button);
}

Chorus::~Chorus()
{
}

void Chorus::paint (Graphics& g)
{
  g.fillAll(Colours::grey);
}

void Chorus::resized()
{
    chorus1Button.setBounds (5, 60,40, 40);
    chorus2Button.setBounds (50, 60, 40, 40);
    
}
