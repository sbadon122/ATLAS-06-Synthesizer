/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessor::SynthFrameworkAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    mUndoManager = new UndoManager();
    tree =  new AudioProcessorValueTreeState (*this, mUndoManager);
    //need these normalisable range objects for the tree state below this
    NormalisableRange<float> attackParam (0.1f, 5000.0f);
    NormalisableRange<float> decayParam (1.0f, 2000.0f);
    NormalisableRange<float> sustainParam (0.0f, 1.0f);
    NormalisableRange<float> releaseParam (0.1f, 5000.0f);
    NormalisableRange<float> waveTypeParam (0, 2);
    NormalisableRange<float> filterParam (30.0f, 4000.0f);
    NormalisableRange<float> resonanceParam (1.0f, 20.0f);
    NormalisableRange<float> filterEnvelopeParam (30.0f, 4000.0f);
    NormalisableRange<float> lfoRateParam (0.0f, 10.0f);
    NormalisableRange<float> lfoDelayParam (30.0f, 50000.0f);
    NormalisableRange<float> lfoFilterParam (0.1f, 5000.0f);
    NormalisableRange<float> hpfParam (5.0f, 19000.0f);
    NormalisableRange<float> vcaParam (0, 1);
    NormalisableRange<float> noiseParam (0, 1);
    NormalisableRange<float> sawButtonParam (0, 1, 0);
    NormalisableRange<float> squareButtonParam (0, 1, 1);
    NormalisableRange<float> subOscParam (0, 1.0f);
    NormalisableRange<float> pitchRangeParam (0, 2);
    NormalisableRange<float> pwmParam (0, 0.99);
    NormalisableRange<float> lfoPitchParam (0, 1.0f);
    NormalisableRange<float> lfoPwmParam (0, 0.99f);
    NormalisableRange<float> chorus1Param (0, 1, 0);
    NormalisableRange<float> chorus2Param (0, 1, 0);
    
    //params that make it possible to set/get states and automate parameters in your DAW.  Also connects values between the slider and the values here
    tree->createAndAddParameter("attack", "Attack", "attack", attackParam, 0.1f, nullptr, nullptr);
    tree->createAndAddParameter("decay", "Decay", "decay", decayParam, 1.0f, nullptr, nullptr);
    tree->createAndAddParameter("sustain", "Sustain", "sustain", sustainParam, 0.8f, nullptr, nullptr);
    tree->createAndAddParameter("release", "Release", "release", releaseParam, 5.0f, nullptr, nullptr);
    tree->createAndAddParameter("wavetype", "WaveType", "wavetype", waveTypeParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("cutoff", "Cutoff", "cutoff", filterParam, 4000.0f,nullptr , nullptr);
    tree->createAndAddParameter("resonance", "Resonance", "resonance", resonanceParam, 1.0f,nullptr , nullptr);
    tree->createAndAddParameter("filterEnvelope", "FilterEnvelope", "filterEnvelope", filterEnvelopeParam, 30.0f,nullptr , nullptr);
    tree->createAndAddParameter("lfoRate", "LfoRate", "lfoRate", lfoRateParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("lfoDelay", "LfoDelay", "lfoDelay", lfoDelayParam, 30.0f,nullptr , nullptr);
    tree->createAndAddParameter("lfoFilterEnvelope", "LfoFilterEnvelope", "lfoFilterEnvelope", lfoFilterParam, 30.0f,nullptr , nullptr);
    tree->createAndAddParameter("hpf", "Hpf", "hpf", hpfParam, 5.0f,nullptr , nullptr);
    tree->createAndAddParameter("vca", "Vca", "vca", vcaParam, 0.75f,nullptr , nullptr);
    tree->createAndAddParameter("noise", "Noise", "noise", noiseParam, 0.0f,nullptr , nullptr);
    tree->createAndAddParameter("sawOsc", "SawOsc", "sawOsc", sawButtonParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("squareOsc", "SquareOsc", "squareOsc", squareButtonParam, 1,nullptr , nullptr);
    tree->createAndAddParameter("subOsc", "SubOsc", "subOsc", subOscParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("range", "Range", "range", pitchRangeParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("pwm", "Pwm", "pwm", pwmParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("lfoPitch", "LfoPitch", "lfoPitch", lfoPitchParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("lfoPwm", "LfoPwm", "lfoPwm", lfoPwmParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("chorus1", "Chorus1", "chorus1", chorus1Param, 0,nullptr , nullptr);
    tree->createAndAddParameter("chorus2", "Chorus2", "chorus2", chorus2Param, 0,nullptr , nullptr);
    
    
    tree->state = ValueTree ("SynthGUI");
    
    mySynth.clearVoices();
    
    for (int i = 0; i < 5; i++)
    {
        mySynth.addVoice(new SynthVoice());
    }
    
    mySynth.clearSounds();
    mySynth.addSound(new SynthSound());
}

SynthFrameworkAudioProcessor::~SynthFrameworkAudioProcessor()
{
}

//==============================================================================
const String SynthFrameworkAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SynthFrameworkAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SynthFrameworkAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SynthFrameworkAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SynthFrameworkAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SynthFrameworkAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SynthFrameworkAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SynthFrameworkAudioProcessor::setCurrentProgram (int index)
{
}

const String SynthFrameworkAudioProcessor::getProgramName (int index)
{
    return {};
}

void SynthFrameworkAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SynthFrameworkAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
  
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void SynthFrameworkAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SynthFrameworkAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SynthFrameworkAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
     ScopedNoDenormals noDenormals;
   
    for (int i = 0; i < mySynth.getNumVoices(); i++)
    {
        
        
        if ((myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i))))
        {
            myVoice->getEnvelopeParams(tree->getRawParameterValue("attack"),
                                       tree->getRawParameterValue("decay"),
                                       tree->getRawParameterValue("sustain"),
                                       tree->getRawParameterValue("release"));
            myVoice->setCutoffSound(tree->getRawParameterValue("cutoff"));
            myVoice->setFitlerResonance(tree->getRawParameterValue("resonance"));
            myVoice->setFilterEnvelopeSetting(tree->getRawParameterValue("filterEnvelope"));
            myVoice->setLfoRateSetting(tree->getRawParameterValue("lfoRate"));
            myVoice->setLfoDelaySetting(tree->getRawParameterValue("lfoDelay"));
            myVoice->setLfoFilterEnvelopeSetting(tree->getRawParameterValue("lfoFilterEnvelope"));
            myVoice->setHpfSetting(tree->getRawParameterValue("hpf"));
            myVoice->setVcaSetting(tree->getRawParameterValue("vca"));
            myVoice->setNoiseSetting(tree->getRawParameterValue("noise"));
            myVoice->setSawOscSetting(tree->getRawParameterValue("sawOsc"));
            myVoice->setSquareOscSetting(tree->getRawParameterValue("squareOsc"));
            myVoice->setSubOscSetting(tree->getRawParameterValue("subOsc"));
            myVoice->setPitchRangeSetting(tree->getRawParameterValue("range"));
            myVoice->setPwmSetting(tree->getRawParameterValue("pwm"));
            myVoice->setLfoPitchSetting(tree->getRawParameterValue("lfoPitch"));
            myVoice->setLfoPwmSetting(tree->getRawParameterValue("lfoPwm"));
            myVoice->setChorus(tree->getRawParameterValue("chorus1"),
                               tree->getRawParameterValue("chorus2"));
        }
    }
    buffer.clear();
    
    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool SynthFrameworkAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SynthFrameworkAudioProcessor::createEditor()
{
    return new SynthFrameworkAudioProcessorEditor (*this);
}

//==============================================================================
void SynthFrameworkAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SynthFrameworkAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SynthFrameworkAudioProcessor();
}
