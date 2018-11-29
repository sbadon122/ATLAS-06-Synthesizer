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
    : AudioProcessorEditor (&p), processor (p), envGui(p), filterGui(p), resonanceGui(p), filterEnvelopeGui(p), lfoGui(p), lfoFilterEnvelopeGui(p), hpfGui(p), vcaGui(p), noiseGui(p), sawOscGui(p), squareOscGui(p), subOscGui(p), pitchRangeGui(p), pwmGui(p), lfoPitchGui(p), lfoPwmGui(p), chorusGui(p), keyboardComponent (p.keyboardState, MidiKeyboardComponent::horizontalKeyboard), presets(p)
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
    addAndMakeVisible(&presets);
    
    
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
    
    addAndMakeVisible(&hpfLabel);
    hpfLabel.setText ("HPF", dontSendNotification);
    hpfLabel.setJustificationType (Justification::centred);
    hpfLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&envAmpLabel);
    envAmpLabel.setText ("ENV", dontSendNotification);
    envAmpLabel.setJustificationType (Justification::centred);
    envAmpLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&ampLabel);
    ampLabel.setText ("AMP", dontSendNotification);
    ampLabel.setJustificationType (Justification::centred);
    ampLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&chorusLabel);
    chorusLabel.setText ("CHORUS", dontSendNotification);
    chorusLabel.setJustificationType (Justification::centred);
    chorusLabel.setFont (Font (16.0f, Font::bold));
    
   
    //Styling LookAndFeel
    getLookAndFeel().setColour (TextButton::buttonColourId,  Colour(0xffe0dedf));
    getLookAndFeel().setColour (TextButton::buttonOnColourId,  Colour(0xffe0dedf));
    lfoGui.setLookAndFeel(&sliderLookAndFeel);
    lfoPwmGui.setLookAndFeel(&sliderLookAndFeel);
    pwmGui.setLookAndFeel(&sliderLookAndFeel);
    subOscGui.setLookAndFeel(&sliderLookAndFeel);
    noiseGui.setLookAndFeel(&sliderLookAndFeel);
    envGui.setLookAndFeel(&sliderLookAndFeel);
    hpfGui.setLookAndFeel(&sliderLookAndFeel);
    filterGui.setLookAndFeel(&sliderLookAndFeel);
    resonanceGui.setLookAndFeel(&sliderLookAndFeel);
    filterEnvelopeGui.setLookAndFeel(&sliderLookAndFeel);
    lfoFilterEnvelopeGui.setLookAndFeel(&sliderLookAndFeel);
    vcaGui.setLookAndFeel(&sliderLookAndFeel);
    
    
}


SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colour(0xff4c494a));
    g.setColour(Colours::darkred);
    g.fillRect (0, 0, 117, 20);
    g.fillRect (120, 0, 440, 20);
    g.fillRect (563, 0, 237, 20);
    g.fillRect (50, 160, 57, 20);
    g.fillRect (145, 160, 200, 20);
    g.fillRect (400, 160, 50, 20);
    g.fillRect (500, 160, 100, 20);
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();
    area.translate(0, 20);
    
    Rectangle<int> area2 = getLocalBounds();
    area2.translate(0, 180);
    
    //Labels
    lfoLabel.setBounds(0,5,100, 10);
    oscLabel.setBounds(120, 0, 440, 20);
    envLabel.setBounds(563, 0, 237, 20);
    hpfLabel.setBounds(50, 160, 57, 20);
    envAmpLabel.setBounds(145, 160, 200, 20);
    ampLabel.setBounds(400, 160, 50, 20);
    chorusLabel.setBounds(500, 160, 100, 20);
    
    //Synth Components
    lfoGui.setBounds(area.removeFromLeft(120).removeFromTop(140));
    pitchRangeGui.setBounds(area.removeFromLeft(140).removeFromTop(140));
    lfoPwmGui.setBounds(area.removeFromLeft(50).removeFromTop(140));
    pwmGui.setBounds(area.removeFromLeft(50).removeFromTop(140));
    squareOscGui.setBounds(area.removeFromLeft(50).removeFromTop(140));
    sawOscGui.setBounds(area.removeFromLeft(50).removeFromTop(140));
    subOscGui.setBounds(area.removeFromLeft(50).removeFromTop(140));
    noiseGui.setBounds(area.removeFromLeft(50).removeFromTop(140));
    envGui.setBounds(area.removeFromLeft(240).removeFromTop(140));
    hpfGui.setBounds(area2.removeFromLeft(150).removeFromTop(300));
    filterGui.setBounds(area2.removeFromLeft(50).removeFromTop(300));
    resonanceGui.setBounds(area2.removeFromLeft(50).removeFromTop(300));
    filterEnvelopeGui.setBounds(area2.removeFromLeft(50).removeFromTop(300));
    lfoFilterEnvelopeGui.setBounds(area2.removeFromLeft(50).removeFromTop(300));
    vcaGui.setBounds(area2.removeFromLeft(150).removeFromTop(300));
    chorusGui.setBounds(area2.removeFromLeft(100).removeFromTop(300));
    presets.setBounds(area2.removeFromLeft(200).removeFromTop(145));
    


    //Keyboard
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


