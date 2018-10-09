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
    : AudioProcessorEditor (&p), processor (p), envGui(p), filterGui(p), resonanceGui(p), filterEnvelopeGui(p), lfoGui(p), lfoFilterEnvelopeGui(p), hpfGui(p), vcaGui(p), noiseGui(p), sawOscGui(p), squareOscGui(p), subOscGui(p), pitchRangeGui(p), pwmGui(p), lfoPitchGui(p), lfoPwmGui(p), chorusGui(p), keyboardComponent (keyboardState, MidiKeyboardComponent::horizontalKeyboard)
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
    keyboardState.addListener(this);
    
    
}


SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::black);
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    const int componentWidth = 200;
    const int componentHeight = 300;
    Rectangle<int> area = getLocalBounds();
    envGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight+10));
    filterGui.setBounds(area.removeFromLeft(50).removeFromTop(componentHeight+10));
    resonanceGui.setBounds(area.removeFromLeft(50).removeFromTop(componentHeight+10));
    filterEnvelopeGui.setBounds(area.removeFromLeft(50).removeFromTop(componentHeight+10));
    lfoGui.setBounds(area.removeFromLeft(100).removeFromTop(componentHeight+10));
    lfoFilterEnvelopeGui.setBounds(area.removeFromLeft(50).removeFromTop(componentHeight+10));
    hpfGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight+10));
    vcaGui.setBounds(10, 150, 45, 150);
    noiseGui.setBounds(50, 150, 45, 150);
    sawOscGui.setBounds(100, 150, 100, 150);
    squareOscGui.setBounds(200, 150, 100, 150);
    subOscGui.setBounds(300, 150, 100, 150);
    pitchRangeGui.setBounds(400, 150, 100, 150);
    pwmGui.setBounds(450, 150, 100, 150);
    lfoPitchGui.setBounds(500, 150, 100, 150);
    lfoPwmGui.setBounds(600, 150, 100, 150);
    chorusGui.setBounds(600, 20, 200, 150);
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

