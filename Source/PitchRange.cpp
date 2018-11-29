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
    //range4Label.attachToComponent(&range4Button, false);
    range4Label.setText("4'", dontSendNotification);
    range4Label.setFont (Font (12.0f, Font::plain));
    range4Label.setJustificationType(Justification::centred);
    
    range8Button.setClickingTogglesState (true);
    addAndMakeVisible (range8Label);
    addAndMakeVisible (range8Button);
    range8Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "range8", range8Button);
    //range8Label.attachToComponent(&range8Button, false);
    range8Label.setText("8'", dontSendNotification);
    range8Label.setFont (Font (12.0f, Font::plain));
    range8Label.setJustificationType(Justification::centred);
    
    range16Button.setClickingTogglesState (true);
    addAndMakeVisible (range16Label);
    addAndMakeVisible (range16Button);
    range16Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "range16", range16Button);
   // range16Label.attachToComponent(&range16Button, false);
    range16Label.setText("16'", dontSendNotification);
    range16Label.setFont (Font (12.0f, Font::plain));
    range16Label.setJustificationType(Justification::centred);
    
    range4Button.addListener(this);
    range8Button.addListener(this);
    range16Button.addListener(this);
    range4Button.setRadioGroupId(1);
    range8Button.setRadioGroupId(1);
    range16Button.setRadioGroupId(1);
}

PitchRange::~PitchRange()
{
}

void PitchRange::paint (Graphics& g)
{
   g.setColour (getButtonColor(&range4Button));
   g.fillEllipse(17.5, 50,5, 5);
   g.setColour (getButtonColor(&range8Button));
   g.fillEllipse(67.5, 50,5, 5);
   g.setColour (getButtonColor(&range16Button));
   g.fillEllipse(117.5, 50,5, 5);
}

Colour PitchRange::getButtonColor(Button* b){
    if(b->getToggleState()){
        return Colour(0xffbe2932);
    }
    else {
        return Colour(0xff5f525d);
    }
}

void PitchRange::resized()
{
    range4Button.setBounds (0, 60,40, 40);
    range8Button.setBounds (50, 60, 40, 40);
    range16Button.setBounds (100, 60, 40, 40);
    
    range4Label.setBounds (0, 17,40, 40);
    range8Label.setBounds (50, 17, 40, 40);
    range16Label.setBounds (100, 17, 40, 40);


}

void PitchRange::buttonClicked (Button* button) // [2]
{
    TextButton* buttons[] = {&range4Button, &range8Button, &range16Button};
    for(int i =0; i<3;i++){
        if(buttons[i]->getToggleState() && buttons[i] != button){
           
            buttons[i]->setToggleState(false, dontSendNotification);
        }
    }
    repaint();
}

