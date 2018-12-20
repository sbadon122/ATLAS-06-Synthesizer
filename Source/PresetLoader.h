/*
  ==============================================================================

    PresetLoader.h
    Created: 11 Nov 2018 5:56:40pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <stdio.h>
#include "PluginProcessor.h"
#include "Constants.h"
#include "SliderLookAndFeel.h"

//==============================================================================
/*
*/
class PresetLoader    : public Component,
                        public FilenameComponentListener,
                        private Button::Listener,
                        private Slider::Listener
{
public:
    PresetLoader(SynthFrameworkAudioProcessor& p);
    ~PresetLoader();

    void paint (Graphics&) override;
    void resized() override;
    void filenameComponentChanged (FilenameComponent* fileComponentThatHasChanged) override;
    void readFile (const File& fileToRead);
    void sliderValueChanged (Slider*) override;

private:
    std::unique_ptr<FilenameComponent> fileComp;
    std::unique_ptr<FileChooser> fc;
    TextButton saveButton    { "" };
    Label saveLabel         { {}, "Save"};
    TextButton initButton    { "" };
    Label initLabel         { {}, "Init"};
    Label synthName         { {}, "Atlas-06"};
    Label portamentoLabel         { {}, "Portamento"};
    Label licenseToLabel         { {}, "Licensed to:"};
    void     buttonClicked (Button *) override;
    void     buttonStateChanged (Button *) override;
    Slider   portamentoSlider;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> portamentoVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> portamentoToggleVal;
    Slider portamentoToggle;
    
    //LookAndFeel
    LookAndFeel_V4 otherLookAndFeel;
    SliderToggleLookAndFeel sliderToggle;
    RotaryLookAndFeel portamentoLookAndFeel;
    
    SynthFrameworkAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetLoader)
};
