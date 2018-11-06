/*
  ==============================================================================

    Range.cpp
    Created: 3 Sep 2018 8:46:48pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PitchRange.h"

//==============================================================================
PitchRange::PitchRange(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    range4Button.setClickingTogglesState (true);
    addAndMakeVisible (range4Label);
    addAndMakeVisible (range4Button);
    range4Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "range4", range4Button);
    
    range8Button.setClickingTogglesState (true);
    addAndMakeVisible (range8Label);
    addAndMakeVisible (range8Button);
    range8Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "range8", range8Button);
    
    range16Button.setClickingTogglesState (true);
    addAndMakeVisible (range16Label);
    addAndMakeVisible (range16Button);
    range16Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "range16", range16Button);
    
    
    range4Button.setRadioGroupId(1);
    range8Button.setRadioGroupId(1);
    range16Button.setRadioGroupId(1);
}

PitchRange::~PitchRange()
{
}

void PitchRange::paint (Graphics& g)
{
   g.fillAll(Colours::grey);
}

void PitchRange::resized()
{
    range4Button.setBounds (5, 60,40, 40);
    range8Button.setBounds (50, 60, 40, 40);
    range16Button.setBounds (95, 60, 40, 40);


}

