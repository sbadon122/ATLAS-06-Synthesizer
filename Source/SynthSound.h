/*
  ==============================================================================

    SynthSound.h
    Created: 25 Jul 2018 12:17:23pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
  public:
    bool appliesToNote(int /*midiNoteNumber*/)
    {
     return true;   
    }
    
    bool appliesToChannel(int /*midiChannel*/){
        return true;
    }
    
};
