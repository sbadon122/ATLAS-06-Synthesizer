/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <stack>
#include "PluginProcessor.h"
#include "Envelope.h"
#include "Cutoff.h"
#include "Resonance.h"
#include "FilterEnvelope.h"
#include "LFO.h"
#include "LfoFilterEnvelope.h"
#include "HPF.h"
#include "VCA.h"
#include "Noise.h"
#include "SawOscillator.h"
#include "SquareOscillator.h"
#include "SubOscillator.h"
#include "PitchRange.h"
#include "PWM.h"
#include "LFOPitch.h"
#include "LFOPWM.h"
#include "Chorus.h"
#include "PresetLoader.h"
#include "SliderLookAndFeel.h"
#include "PWMModeSwitch.h"
#include "PolaritySwitch.h"
#include "PitchBend.h"



//==============================================================================
/**
*/
class SynthFrameworkAudioProcessorEditor  : public AudioProcessorEditor,
                                            private MidiInputCallback,
                                            private MidiKeyboardStateListener
{
public:
    SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor&);
    ~SynthFrameworkAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void handleNoteOn (MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity) override;
    void handleNoteOff(MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity) override;
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override;
    void sliderValueChanged (Slider* slider);
    void drawSquareLabel(float x, float y, int size, float thickness, Graphics& g);
    void drawSawLabel(float x, float y, int size, float thickness, Graphics& g);
    void drawDCOLabelLines(float x, float y, float width, float thickness, Graphics& g);
    void drawSeparatingWhiteLines(float x, float y, float height, float thickness, Graphics& g);
    void drawPolarityModeLabel(float x, float y, float size,  float thickness, bool flip, Graphics& g);
    void drawGateLabel(float x, float y, int size, float thickness, Graphics& g);
    void drawAmpWhiteLabelLine(float x, float y,  float thickness, Graphics& g);
    void drawEnvWhiteLabelLine(float x, float y,  float thickness, Graphics& g);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;
    
    Envelope envGui;
    Cutoff filterGui;
    Resonance resonanceGui;
    FilterEnvelope filterEnvelopeGui;
    LFO lfoGui;
    HPF hpfGui;
    VCA vcaGui;
    Noise noiseGui;
    SawOscillator sawOscGui;
    SquareOscillator squareOscGui;
    SubOscillator subOscGui;
    LfoFilterEnvelope lfoFilterEnvelopeGui;
    PitchRange pitchRangeGui;
    LFOPitch lfoPitchGui;
    LFOPWM lfoPwmGui;
    Chorus chorusGui;
    PWM pwmGui;
    MidiKeyboardComponent keyboardComponent;
    PresetLoader presets;
    PWMModeSwitch pwmModeSwitchGui;
    PolaritySwitch polaritySwitchGui;
    PitchBend pitchBendGui;
    //Labels
    Label lfoLabel;
    Label oscLabel;
    Label envLabel;
    Label hpfLabel;
    Label envAmpLabel;
    Label ampLabel;
    Label chorusLabel;
    
    SliderLookAndFeel sliderLookAndFeel;
    SliderToggleLookAndFeel sliderToggleLookAndFeel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthFrameworkAudioProcessorEditor)
};
