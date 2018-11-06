/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), envGui(p), filterGui(p), resonanceGui(p), filterEnvelopeGui(p), lfoGui(p), lfoFilterEnvelopeGui(p), hpfGui(p), vcaGui(p), noiseGui(p), sawOscGui(p), squareOscGui(p), subOscGui(p), pitchRangeGui(p), pwmGui(p), lfoPitchGui(p), lfoPwmGui(p), chorusGui(p), keyboardComponent (p.keyboardState, MidiKeyboardComponent::horizontalKeyboard)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 400);
    addAndMakeVisible(&envGui);
    addAndMakeVisible(&filterGui);
    addAndMakeVisible(&resonanceGui);
    addAndMakeVisible(&filterEnvelopeGui);
    addAndMakeVisible(&lfoGui);
    addAndMakeVisible(&lfoFilterEnvelopeGui);
    addAndMakeVisible(&hpfGui);
    addAndMakeVisible(&vcaGui);
    addAndMakeVisible(&noiseGui);
    addAndMakeVisible(&sawOscGui);
    addAndMakeVisible(&squareOscGui);
    addAndMakeVisible(&subOscGui);
    addAndMakeVisible(&pitchRangeGui);
    addAndMakeVisible(&pwmGui);
    addAndMakeVisible(&lfoPitchGui);
    addAndMakeVisible(&lfoPwmGui);
    addAndMakeVisible(&chorusGui);
    addAndMakeVisible(&keyboardComponent);
    
    
    //Labels
    addAndMakeVisible(&lfoLabel);
    lfoLabel.setText ("LFO", dontSendNotification);
    lfoLabel.setJustificationType (Justification::centred);
    lfoLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&oscLabel);
    oscLabel.setText ("DCO", dontSendNotification);
    oscLabel.setJustificationType (Justification::centred);
    oscLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&envLabel);
    envLabel.setText ("ENV", dontSendNotification);
    envLabel.setJustificationType (Justification::centred);
    envLabel.setFont (Font (16.0f, Font::bold));
    
    
}


SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::black);
    g.setColour(Colours::darkred);
    g.fillRect (0, 0, 117, 20);
    g.fillRect (120, 0, 440, 20);
    g.fillRect (563, 0, 237, 20);
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();
    area.translate(0, 20);
    
    //Labels
    lfoLabel.setBounds(0,5,100, 10);
    oscLabel.setBounds(120, 0, 440, 20);
    envLabel.setBounds(563, 0, 237, 20);
    
    //Synth Components
    lfoGui.setBounds(area.removeFromLeft(120).removeFromTop(150));
    pitchRangeGui.setBounds(area.removeFromLeft(140).removeFromTop(150));
    lfoPwmGui.setBounds(area.removeFromLeft(50).removeFromTop(150));
    pwmGui.setBounds(area.removeFromLeft(50).removeFromTop(150));
    squareOscGui.setBounds(area.removeFromLeft(50).removeFromTop(150));
    sawOscGui.setBounds(area.removeFromLeft(50).removeFromTop(150));
    subOscGui.setBounds(area.removeFromLeft(50).removeFromTop(150));
    noiseGui.setBounds(area.removeFromLeft(50).removeFromTop(150));
    envGui.setBounds(area.removeFromLeft(240).removeFromTop(150));
    keyboardComponent.setBounds(0, 325, 800, 75);
    
}

void SynthFrameworkAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
 
    
}

void SynthFrameworkAudioProcessorEditor::handleNoteOn(MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity)
{
 
}

void SynthFrameworkAudioProcessorEditor::handleNoteOff(MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity)
{

}

void SynthFrameworkAudioProcessorEditor::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{
   
}

