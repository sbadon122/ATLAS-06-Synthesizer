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
    checkSynthLicense();
    mUndoManager = new UndoManager();
    tree =  new AudioProcessorValueTreeState (*this, mUndoManager);
    //need these normalisable range objects for the tree state below this
    NormalisableRange<float> attackParam (0.1f, 5000.0f);
    NormalisableRange<float> decayParam (1.0f, 2000.0f);
    NormalisableRange<float> sustainParam (0.0f, 1.0f);
    NormalisableRange<float> releaseParam (0.1f, 5000.0f);
    NormalisableRange<float> filterParam (30.0f, 6000.0f);
    NormalisableRange<float> resonanceParam (1.0f, 20.0f);
    NormalisableRange<float> filterEnvelopeParam (30.0f, 4000.0f);
    NormalisableRange<float> lfoRateParam (0.0f, 10.0f);
    NormalisableRange<float> lfoDelayParam (30.0f, 50000.0f);
    NormalisableRange<float> lfoFilterParam (0.1f, 5000.0f);
    NormalisableRange<float> hpfParam (10.0f, 6000.0f);
    NormalisableRange<float> vcaParam (0, 5);
    NormalisableRange<float> noiseParam (0, 1);
    NormalisableRange<float> sawButtonParam (0, 1, 0);
    NormalisableRange<float> squareButtonParam (0, 1, 1);
    NormalisableRange<float> subOscParam (0, 1.0f);
    NormalisableRange<float> pitchRangeParam (0, 1);
    NormalisableRange<float> pitchRangeParam2 (0, 1);
    NormalisableRange<float> pitchRangeParam3 (0, 1);
    NormalisableRange<float> pwmParam (0, 0.99);
    NormalisableRange<float> lfoPitchParam (0, 1.0f);
    NormalisableRange<float> lfoPwmParam (0, 0.99f);
    NormalisableRange<float> chorus1Param (0, 1, 0);
    NormalisableRange<float> chorus2Param (0, 1, 0);
    NormalisableRange<float> pwmModeToggle (0, 1, 0);
    NormalisableRange<float> polarityModeToggle (-1, 1, 1);
    NormalisableRange<float> pitchBendParam (-1.0f, 1.0f);
    NormalisableRange<float> dcoSliderPitchBendParam (0, 1.0f);
    NormalisableRange<float> vcfSliderPitchBendParam (0, 4000.0f);
    NormalisableRange<float> portamentoParam (0, 0.99f);
    NormalisableRange<float> portamentoToggleParam (-1.0f, 1.0f);
    NormalisableRange<float> ampParam (0, 1);
    
    //params that make it possible to set/get states and automate parameters in your DAW.  Also connects values between the slider and the values here
    tree->createAndAddParameter("attack", "Attack", "attack", attackParam, 0.1f, nullptr, nullptr);
    tree->createAndAddParameter("decay", "Decay", "decay", decayParam, 1.0f, nullptr, nullptr);
    tree->createAndAddParameter("sustain", "Sustain", "sustain", sustainParam, 0.8f, nullptr, nullptr);
    tree->createAndAddParameter("release", "Release", "release", releaseParam, 5.0f, nullptr, nullptr);
    tree->createAndAddParameter("cutoff", "Cutoff", "cutoff", filterParam, 4000.0f,nullptr , nullptr);
    tree->createAndAddParameter("resonance", "Resonance", "resonance", resonanceParam, 1.0f,nullptr , nullptr);
    tree->createAndAddParameter("filterEnvelope", "FilterEnvelope", "filterEnvelope", filterEnvelopeParam, 30.0f,nullptr , nullptr);
    tree->createAndAddParameter("lfoRate", "LfoRate", "lfoRate", lfoRateParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("lfoDelay", "LfoDelay", "lfoDelay", lfoDelayParam, 30.0f,nullptr , nullptr);
    tree->createAndAddParameter("lfoFilterEnvelope", "LfoFilterEnvelope", "lfoFilterEnvelope", lfoFilterParam, 30.0f,nullptr , nullptr);
    tree->createAndAddParameter("hpf", "Hpf", "hpf", hpfParam, 10.0f,nullptr , nullptr);
    tree->createAndAddParameter("vca", "Vca", "vca", vcaParam, 2.5f,nullptr , nullptr);
    tree->createAndAddParameter("noise", "Noise", "noise", noiseParam, 0.0f,nullptr , nullptr);
    tree->createAndAddParameter("sawOsc", "SawOsc", "sawOsc", sawButtonParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("squareOsc", "SquareOsc", "squareOsc", squareButtonParam, 1,nullptr , nullptr);
    tree->createAndAddParameter("subOsc", "SubOsc", "subOsc", subOscParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("range4", "Range4", "range4", pitchRangeParam, 1,nullptr , nullptr);
    tree->createAndAddParameter("range8", "Range8", "range8", pitchRangeParam2, 0,nullptr , nullptr);
    tree->createAndAddParameter("range16", "Range16", "range16", pitchRangeParam3, 0,nullptr , nullptr);
    tree->createAndAddParameter("pwm", "Pwm", "pwm", pwmParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("lfoPitch", "LfoPitch", "lfoPitch", lfoPitchParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("lfoPwm", "LfoPwm", "lfoPwm", lfoPwmParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("chorus1", "Chorus1", "chorus1", chorus1Param, 0,nullptr , nullptr);
    tree->createAndAddParameter("chorus2", "Chorus2", "chorus2", chorus2Param, 0,nullptr , nullptr);
    tree->createAndAddParameter("pwmMode", "PwmMode", "pwmMode", pwmModeToggle, 0,nullptr , nullptr);
    tree->createAndAddParameter("pitchBend", "PitchBend", "pitchBend", pitchBendParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("dcoSliderPitchBend", "DcoSliderPitchBend", "dcoSliderPitchBend", dcoSliderPitchBendParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("vcfSliderPitchBend", "VcfSliderPitchBend", "vcfSliderPitchBend", vcfSliderPitchBendParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("portamento", "Portamento", "portamento", portamentoParam, 0,nullptr , nullptr);
    tree->createAndAddParameter("portamentoToggle", "PortamentoToggle", "portamentoToggle", portamentoToggleParam, -1,nullptr , nullptr);
    tree->createAndAddParameter("ampMode", "AmpMode", "ampMode", ampParam, 1,nullptr , nullptr);
    
    
    tree->createAndAddParameter("polarityMode", "PolarityMode", "polarityMode", polarityModeToggle, 1,nullptr , nullptr);
    
    tree->state = ValueTree ("synth");
    
    initState.reset(tree->state.createXml());
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
    initState = nullptr;
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
   auto numSamples = buffer.getNumSamples();
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
            myVoice->setPitchRangeSetting(tree->getRawParameterValue("range4"),tree->getRawParameterValue("range8"), tree->getRawParameterValue("range16"));
            myVoice->setPwmSetting(tree->getRawParameterValue("pwm"));
            myVoice->setLfoPitchSetting(tree->getRawParameterValue("lfoPitch"));
            myVoice->setLfoPwmSetting(tree->getRawParameterValue("lfoPwm"));
            myVoice->setPolarityModeSetting(tree->getRawParameterValue("polarityMode"));
            myVoice->setPwmMode(tree->getRawParameterValue("pwmMode"));
            myVoice->setPitchBendSetting(tree->getRawParameterValue("pitchBend"));
            myVoice->setDcoPitchBendSetting(tree->getRawParameterValue("dcoSliderPitchBend"));
            myVoice->setVcfPitchBendSetting(tree->getRawParameterValue("vcfSliderPitchBend"));
            myVoice->setPortamentoSetting(tree->getRawParameterValue("portamento"));
            myVoice->setPortomentoToggle(tree->getRawParameterValue("portamentoToggle"));
            myVoice->setAmpMode(tree->getRawParameterValue("ampMode"));
            myVoice->setChorus(tree->getRawParameterValue("chorus1"),
                               tree->getRawParameterValue("chorus2"));
        }
    }
    buffer.clear();
    keyboardState.processNextMidiBuffer (midiMessages, 0, numSamples, true);
   
    if(synthIsRegistered){
        mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
    }
    
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
    
    ScopedPointer <XmlElement> xml (tree->state.createXml());
    copyXmlToBinary(*xml, destData);
}

void SynthFrameworkAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    ScopedPointer <XmlElement> paramsXml (getXmlFromBinary(data,sizeInBytes));
    
    if( paramsXml != nullptr) {
        if(paramsXml -> hasTagName(tree->state.getType())) {
            tree->state = ValueTree::fromXml(*paramsXml);
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SynthFrameworkAudioProcessor();
}

void SynthFrameworkAudioProcessor::initializeSynth (){
    tree->replaceState(ValueTree::fromXml(*initState));
}

void SynthFrameworkAudioProcessor::checkSynthLicense (){
   File file ("~/documents/Vega-06/license.vega");
    if (! file.existsAsFile())
        return;
    
    std::string fileText =  file.loadFileAsString().toStdString();
    char encryptedText[fileText.size()+1];
    
    const char* strdata = fileText.c_str();
    for (int i = 0; i < fileText.length(); ++i){
       char c =  strdata[i] - 2;
       encryptedText[i] = c;
    }
    CharPointer_UTF8 utf8CharPointer(encryptedText);
    String decryptedText(utf8CharPointer);
    String activated = decryptedText.substring(0, 21);
    if(activated.compare(activationString) == 0 ) {
        synthOwner = decryptedText.substring(21, decryptedText.length()-2);
        synthIsRegistered = true;
    }
}

String SynthFrameworkAudioProcessor::getOwnersName(){
    return synthOwner;
}



