/*
  ==============================================================================

    ChorusEffect.h
    Created: 5 Sep 2018 7:04:59pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once
#include "maximilian.h"

class ChorusEffect
{
public:
    ChorusEffect();
    ~ChorusEffect();
    
    double processSignal(float sample, double lfoRate);
private:
    maxiOsc lfo;
    maxiFractionalDelay delay;
    double previousSample;
    
};
