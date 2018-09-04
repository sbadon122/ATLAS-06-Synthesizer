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
    rangeMenu.addItem("4", 1);
    rangeMenu.addItem("8", 2);
    rangeMenu.addItem("16", 3);
    addAndMakeVisible(&rangeMenu);
    rangeMenu.addListener(this);
    
    rangeMenu.setJustificationType(Justification::centred);
    rangeSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(*processor.tree, "range", rangeMenu);

}

PitchRange::~PitchRange()
{
}

void PitchRange::paint (Graphics& g)
{
   
}

void PitchRange::resized()
{
    
    rangeMenu.setBounds(10, 30, 40, 30);

}

void PitchRange::comboBoxChanged(ComboBox* box)
{
    
}
