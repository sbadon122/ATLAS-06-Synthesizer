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

class SynthVoice : public SynthesiserVoice
{
    public:
        bool canPlaySound(SynthesiserSound* sound)
        {
            return dynamic_cast<SynthSound*>(sound) != nullptr;
        }
        
        void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
        {
            env1.trigger = 1;
            level = velocity;
            frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        }
        
        void stopNote(float velocity, bool allowTailOff)
        {
            env1.trigger = 0;
            allowTailOff = true;
            if (velocity == 0)
                clearCurrentNote();
            
        }
        
        void pitchWheelMoved(int newPitchWheelValue)
        {
        }
        
        void controllerMoved(int controllerNumber, int newControllerValue)
        {
        }
    
        void renderNextBlock(AudioBuffer<float> &outputBuffer,int startSample, int numSamples)
        {
            env1.setAttack(2000);
            env1.setDecay(500);
            env1.setSustain(.8);
            env1.setRelease(2000);
            
            for(int sample =0; sample < numSamples; ++sample)
            {
                double theWave = osc1.saw (frequency);
                double theSound = env1.adsr(theWave, env1.trigger) * level;
                double filterSound = filter1.lores(theSound, 100, 0.1);
                
                for(int channel =0; channel < outputBuffer.getNumChannels(); ++channel)
                {
                    outputBuffer.addSample(channel, startSample, filterSound);
                }
                ++startSample;
            }
            
        }
        
    private:
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;
    double level;
    double frequency;
};
