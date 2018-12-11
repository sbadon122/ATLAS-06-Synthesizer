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
    chorus1Label.setText("i", dontSendNotification);
    chorus1Label.setFont (Font (12.0f, Font::plain));
    chorus1Label.setJustificationType(Justification::centred);
    chorus1Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "chorus1", chorus1Button);
    
    chorus2Button.setClickingTogglesState (true);
    addAndMakeVisible (chorus2Label);
    addAndMakeVisible (chorus2Button);
    chorus2Label.setText("ii", dontSendNotification);
    chorus2Label.setFont (Font (12.0f, Font::plain));
    chorus2Label.setJustificationType(Justification::centred);
    chorus2Val = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "chorus2", chorus2Button);
    
    chorus1Button.addListener(this);
    chorus2Button.addListener(this);
    
    otherLookAndFeel.setColour (TextButton::buttonColourId,  Colour(0xfff9ac02));
    otherLookAndFeel.setColour (TextButton::buttonOnColourId,  Colour(0xfff9ac02));
    chorus1Button.setLookAndFeel(&otherLookAndFeel);
    chorus2Button.setLookAndFeel(&otherLookAndFeel);
}

Chorus::~Chorus()
{
}

void Chorus::paint (Graphics& g)
{
 
  g.setColour (getButtonColor(&chorus1Button));
   g.fillEllipse(22.5, 55,5, 5);
  g.setColour (getButtonColor(&chorus2Button));
  g.fillEllipse(62.5, 55,5, 5);

}

void Chorus::resized()
{
    chorus1Button.setBounds (10, 70,buttonSize, buttonSize);
    chorus2Button.setBounds (50, 70, buttonSize, buttonSize);
    
    chorus1Label.setBounds (10, 30,buttonSize, buttonSize);
    chorus2Label.setBounds (50, 30, buttonSize, buttonSize);
    
    
}

Colour Chorus::getButtonColor(Button* b){
    if(b->getToggleState()){
        return Colour(0xffbe2932);
    }
    else {
        return Colour(0xff5f525d);
    }
}

void Chorus::buttonClicked (Button* button)
{
    repaint();
}

