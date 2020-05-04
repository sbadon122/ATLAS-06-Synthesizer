/*
  ==============================================================================

    ChorusEffect.cpp
    Created: 5 Sep 2018 7:04:59pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "ChorusEffect.h"


ChorusEffect::ChorusEffect() { }
ChorusEffect::~ChorusEffect() { }

double ChorusEffect::processSignal(float sample, double lfoRate){
    double delayedSample = 0;
    delayedSample = delay.dl(sample, 1 + 175*( 1 + lfo.sinebuf4(lfoRate)), 0);
    return sample + delayedSample;
}


