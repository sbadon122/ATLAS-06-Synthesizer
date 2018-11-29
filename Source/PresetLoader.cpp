/*
  ==============================================================================

    PresetLoader.cpp
    Created: 11 Nov 2018 5:56:40pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PresetLoader.h"

//==============================================================================
PresetLoader::PresetLoader(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    //File Selector
    fileComp.reset (new FilenameComponent ("fileComp", {}, false, false, false, {},   {}, "Presets"));
    addAndMakeVisible (fileComp.get());
    fileComp->addListener (this);
    fileComp->setTooltip("Select Preset");
    fileComp->setBrowseButtonText("Load Preset");
    
    saveButton.setClickingTogglesState (true);
    addAndMakeVisible (saveLabel);
    addAndMakeVisible (saveButton);
    saveLabel.attachToComponent(&saveButton, false);
    saveLabel.setText("Save", dontSendNotification);
    saveLabel.setFont (Font (12.0f, Font::plain));
    saveLabel.setJustificationType(Justification::centred);
    saveButton.addListener(this);
    
    otherLookAndFeel.setColour (TextButton::buttonColourId,  Colour(0xffe0dedf));
    otherLookAndFeel.setColour (TextButton::buttonOnColourId,  Colour(0xffe0dedf));
    otherLookAndFeel.setColour (TextButton::textColourOnId,  Colours::black);
    otherLookAndFeel.setColour (TextButton::textColourOffId,  Colours::black);
    otherLookAndFeel.setColour (ComboBox::backgroundColourId,  Colour(0xffe0dedf));
    otherLookAndFeel.setColour (ComboBox::textColourId,  Colours::black);
    otherLookAndFeel.setColour (ComboBox::arrowColourId,  Colours::black);
    saveButton.setLookAndFeel(&otherLookAndFeel);
    fileComp->setLookAndFeel(&otherLookAndFeel);

}

PresetLoader::~PresetLoader()
{
}

void PresetLoader::paint (Graphics& g)
{   
  
}

void PresetLoader::resized()
{
    fileComp->setBounds(20, 15, 160, 20);
    saveButton.setBounds(75, 60,40, 40);

}

void PresetLoader::filenameComponentChanged (FilenameComponent* fileComponentThatHasChanged)
{
    FileInputStream stream(fileComponentThatHasChanged->getCurrentFile());
    XmlDocument xmlDocument(stream.readEntireStreamAsString());
    std::unique_ptr<XmlElement> paramsXml (xmlDocument.getDocumentElement());
    if(paramsXml -> hasTagName(processor.tree->state.getType())) {
        processor.tree->state = ValueTree::fromXml(*paramsXml);
    }
}

void PresetLoader::readFile (const File& fileToRead)
{
    
}

void PresetLoader::buttonClicked(Button* button){
    auto fileToSave = File::createTempFile ("saveChooserDemo");

    if (fileToSave.createDirectory().wasOk())
    {
        fileToSave = fileToSave.getChildFile ("preset.islnds");
        fileToSave.deleteFile();
        
    }
    FileOutputStream outStream (fileToSave);
    
    if (outStream.openedOk()){
        outStream.setPosition(0);
        outStream.truncate();
        String xml =  processor.tree->state.toXmlString();;
       
        StringRef ext ("islnds");
        StringRef encoding("UTF-8");
        outStream.writeString(xml);
        
        
    }
    
    fc.reset (new FileChooser ("Choose a file to save...",
                               File::getCurrentWorkingDirectory().getChildFile (fileToSave.getFileName()),
                               "*",  true));
   


    fc->launchAsync (FileBrowserComponent::saveMode | FileBrowserComponent::canSelectFiles,
                     [fileToSave] (const FileChooser& chooser)
                     {
                         auto result = chooser.getURLResult();
                         auto name = result.isEmpty() ? String()
                         : (result.isLocalFile() ? result.getLocalFile().getFullPathName()
                            : result.toString (true));
                         if (! result.isEmpty())
                         {
                             std::unique_ptr<InputStream>  wi (fileToSave.createInputStream());
                             std::unique_ptr<OutputStream> wo (result.createOutputStream());
                             
                             if (wi.get() != nullptr && wo.get() != nullptr)
                             {
                                 auto numWritten = wo->writeFromInputStream (*wi, -1);
                                 jassert (numWritten > 0);
                                 ignoreUnused (numWritten);
                                 wo->flush();
                             }
                         }
                     });
    

   
}
                

void PresetLoader::buttonStateChanged(Button* button){
    
}
