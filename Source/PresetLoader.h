/*
  ==============================================================================

    PresetLoader.h
    Created: 11 Nov 2018 5:56:40pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class PresetLoader    : public Component,
                        public FilenameComponentListener,
                        private Button::Listener
{
public:
    PresetLoader(SynthFrameworkAudioProcessor& p);
    ~PresetLoader();

    void paint (Graphics&) override;
    void resized() override;
    void filenameComponentChanged (FilenameComponent* fileComponentThatHasChanged) override;
    void readFile (const File& fileToRead);

private:
    std::unique_ptr<FilenameComponent> fileComp;
    std::unique_ptr<FileChooser> fc;
    TextButton saveButton    { "" };
    Label saveLabel         { {}, "Save'"};
    void     buttonClicked (Button *) override;
    void     buttonStateChanged (Button *) override;
    
    //LookAndFeel
    LookAndFeel_V4 otherLookAndFeel;
    
    SynthFrameworkAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetLoader)
};
