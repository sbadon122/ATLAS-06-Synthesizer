/*
  ==============================================================================

    SynthVoice.h
    Created: 25 Jul 2018 12:17:30pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"
#include "ChorusEffect.h"

class SynthVoice : public SynthesiserVoice
{
    public:
    bool canPlaySound(SynthesiserSound* sound) override
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    void getEnvelopeParams(float* attack, float* decay, float* sustain, float* release)
    {
            env1.setAttack(*attack);
            env1.setDecay(*decay);
            env1.setSustain(*sustain);
            env1.setRelease(*release);
    }
    
    void setCutoffSound(float* setting)
    {
        cutoffSetting = *setting;
    }
    
    void setFitlerResonance(float* setting)
    {
        resonanceSetting = *setting;
    }
    
    void setFilterEnvelopeSetting(float* setting)
    {
        filterEnvelopeSetting = *setting;
    }
    
    void setPolarityModeSetting(float* setting) {
        polarityModeSetting = *setting;
    }
    
    void setLfoFilterEnvelopeSetting(float* setting)
    {
        lfoFilterEnvelopeSetting = *setting;
    }
    
    void setLfoRateSetting(float* setting)
    {
        lfoRateSetting = *setting;
    }
    
    
    void setLfoDelaySetting(float* setting)
    {
        lfoEnv.setAttack(*setting);
        lfoEnv.setDecay(1.0f);
        lfoEnv.setSustain(1.0f);
        lfoEnv.setRelease(1.0f);
        lfoDelaySetting = *setting;
    }
    
    void setHpfSetting(float* setting)
    {
        hpfSetting = *setting;
    }
    
    void setVcaSetting(float* setting)
    {
        vcaSetting = *setting;
    }
    
    void setNoiseSetting(float* setting)
    {
        noiseSetting = *setting;
    }
    void setPwmMode(float* setting){
        pwmModeSetting = *setting;
    }
    
    void setSawOscSetting(float* setting)
    {
        sawOscSetting = *setting;
    }
    
    void setSquareOscSetting(float* setting)
    {
        squareOscSetting = *setting;
    }
    
    void setSubOscSetting(float* setting)
    {
        subOscSetting = *setting;
    }
    
    void setPitchRangeSetting(float* range4, float* range8, float* range16)
    {
        if(*range4 == 1) {
            pitchRangeSetting = 0;
        }
        else if(*range8 == 1) {
             pitchRangeSetting = 1;
        }
        else if(*range16 == 1) {
            pitchRangeSetting = 2;
        }
    }
    
    void setPwmSetting(float* setting)
    {
        pwmSetting = *setting;
    }
    
    double getPwmSetting(){
        double pwm = pwmSetting;
        pwm = pwmSetting - pwmSetting * lfoPwmSetting * pwmModeSetting * getLfoValue();
        if(pwm > 0.99f){
            return 0.99;
        } else if (pwm < 0){
            return 0;
        } else {
            return pwm;
        }
    }
    
    void setChorus(float* chorus1, float* chorus2){
        chorus1Setting = *chorus1;
        chorus2Setting = *chorus2;
    }
    
    double getPitchRangeSetting()
    {
        if(pitchRangeSetting == 1)
        {
            return 4;
        }
        else if(pitchRangeSetting == 2)
        {
            return 8;
        }
        return 1;
    }
    
    void setLfoPitchSetting(float* setting){
        lfoPitchSetting = *setting;
    }
    
    void setLfoPwmSetting(float* setting){
        lfoPwmSetting = *setting;
    }
    
    double getSawOsc() {
        if(sawOscSetting)
        {
            return sawOsc.saw(processedFrequency/getPitchRangeSetting());
        }
        return 0;
    }
    
    double getSquareOsc() {
        if(squareOscSetting)
        {
            double squareFrequency = squareOsc.square(processedFrequency/getPitchRangeSetting());
            if(pwmSetting > 0){
            return squareOsc.pulse(squareFrequency, getPwmSetting());
            } else {
                return squareFrequency;
            }
            
        }
        return 0;
    }
    
    double getSubOsc() {
        if(subOscSetting > 0)
        {
            return subOsc.square(processedFrequency/4/getPitchRangeSetting()) * subOscSetting;
        }
        return 0;
    }
    
    double getDCOSound(){
        double noiseValue = osc1.noise() * noiseSetting;
        double dcoSound = getSawOsc() + getSquareOsc() + getSubOsc() +  noiseValue;
        return dcoSound;
    }
    
    double getLfoValue()
    {
        double lfoValue = lfoRateSetting != 0 ? lfo.sinewave(lfoEnv.adsr(lfoRateSetting , lfoEnv.trigger)) : 0;
        return lfoValue;
    }
        
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override
        {
            env1.trigger = 1;
            lfoEnv.trigger = 1;
            level = velocity;
            frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        }
        
        void stopNote(float velocity, bool allowTailOff) override
        {
            env1.trigger = 0;
            env1.attackphase=0;
            env1.decayphase=1;
            lfoEnv.trigger = 0;
            lfoEnv.attackphase=0;
            lfoEnv.decayphase=1;
            allowTailOff = true;
            if (velocity == 0)
                clearCurrentNote();
            
        }
        
        void pitchWheelMoved(int newPitchWheelValue) override
        {
        }
        
        void controllerMoved(int controllerNumber, int newControllerValue) override
        {
        }
    
    
        double calculateFilterCutoff(double currentVolume)
        {
            double cutoffValue = 0;
             if(cutoffSetting > filterEnvelopeSetting && polarityModeSetting == 1.0)
             {
                 cutoffValue = cutoffSetting;
             }
            else if(cutoffSetting < filterEnvelopeSetting && polarityModeSetting == -1.0)
            {
                cutoffValue = cutoffSetting;
            }
            else if(polarityModeSetting == 1.0)
            {
                cutoffValue = currentVolume*filterEnvelopeSetting;
            }
            else if(polarityModeSetting == -1.0)
            {
                cutoffValue = filterEnvelopeSetting/currentVolume;
            }
            
            cutoffValue += getLfoValue()*lfoFilterEnvelopeSetting;
            if(cutoffValue < 30.0f)
            {
                cutoffValue = 30.0f;
            }
            else if (cutoffValue > 4000.0f)
            {
                cutoffValue = 4000.0f;
            }
            return cutoffValue;
        }
    
        double getChorusRate(){
            double chorusRate = 0;
            if(chorus1Setting > 0){ chorusRate += 0.2; }
            if(chorus2Setting > 0){ chorusRate += 0.4; }
            return chorusRate;
        }
    
        void renderNextBlock(AudioBuffer<float> &outputBuffer,int startSample, int numSamples) override
        {
        
            
            for (int sample = 0; sample < numSamples; ++sample)
            {
                double myCurrentVolume = env1.adsr(1., env1.trigger) * level * vcaSetting;
                processedFrequency = frequency + (frequency * getLfoValue() * lfoPitchSetting);
                double oscSound = getDCOSound();
                double filteredSound = filter1.lores(oscSound*myCurrentVolume, calculateFilterCutoff(myCurrentVolume), resonanceSetting);
                double processedSound = filter1.hires(filteredSound, hpfSetting, 0);
                double chorusRate = getChorusRate();
                if(chorusRate > 0) {
                    processedSound = chorusEffect.processSignal(processedSound, chorusRate);
                }
                for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
                {
                    outputBuffer.addSample(channel, startSample, processedSound);
                }
                ++startSample;
            }
            
            
        }
        
    private:
    maxiOsc osc1;
    maxiOsc sawOsc;
    maxiOsc squareOsc;
    maxiOsc subOsc;
    maxiEnv env1;
    maxiEnv lfoEnv;
    maxiFilter filter1;
    maxiOsc lfo;
    ChorusEffect chorusEffect;
    double level;
    double frequency;
    double processedFrequency;
    double cutoffSetting;
    double resonanceSetting;
    double filterEnvelopeSetting;
    double pwmSetting;
    double hpfSetting;
    double vcaSetting;
    double noiseSetting;
    double sawOscSetting;
    double squareOscSetting;
    double subOscSetting;
    double pitchRangeSetting;
    double lfoRateSetting;
    double lfoDelaySetting;
    double lfoFilterEnvelopeSetting;
    double lfoPitchSetting;
    double lfoPwmSetting;
    double chorus1Setting;
    double chorus2Setting;
    double pwmModeSetting;
    double polarityModeSetting;
    
    
};
