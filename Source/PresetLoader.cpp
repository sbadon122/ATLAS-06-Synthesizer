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
    saveLabel.setText("SAVE", dontSendNotification);
    saveButton.setName("save");
    saveLabel.setFont (Font (10.0f, Font::plain));
    saveLabel.setJustificationType(Justification::centred);
    saveButton.addListener(this);
    
    addAndMakeVisible (initLabel);
    addAndMakeVisible (initButton);
    initLabel.attachToComponent(&initButton, false);
    initLabel.setText("INIT", dontSendNotification);
    initLabel.setFont (Font (10.0f, Font::plain));
    initButton.setName("init");
    initLabel.setJustificationType(Justification::centred);
    initButton.addListener(this);
    
    addAndMakeVisible (synthName);
    synthName.setText("ATLAS-06", dontSendNotification);
    synthName.setFont (Font (30.0f, Font::bold));
    synthName.setColour(Label::ColourIds::textColourId, Colours::black);
    synthName.setJustificationType(Justification::centred);
    
    addAndMakeVisible (licenseToLabel);
    licenseToLabel.setText("Licensed to: " + p.getOwnersName() , dontSendNotification);
    licenseToLabel.setFont (Font (10.0f, Font::plain));
    licenseToLabel.setColour(Label::ColourIds::textColourId, Colours::whitesmoke);
    licenseToLabel.setJustificationType(Justification::right);
    
    portamentoSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    portamentoSlider.setRange(0, 0.99f);
    portamentoSlider.setValue(0);
    portamentoSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&portamentoSlider);

    addAndMakeVisible (portamentoLabel);
    portamentoLabel.setFont (Font (10.0f, Font::plain));
    
    
    otherLookAndFeel.setColour (TextButton::buttonColourId,  Colour(0xffe0dedf));
    otherLookAndFeel.setColour (TextButton::buttonOnColourId,  Colour(0xffe0dedf));
    otherLookAndFeel.setColour (TextButton::textColourOnId,  Colours::black);
    otherLookAndFeel.setColour (TextButton::textColourOffId,  Colours::black);
    otherLookAndFeel.setColour (ComboBox::backgroundColourId,  Colour(0xffe0dedf));
    otherLookAndFeel.setColour (ComboBox::textColourId,  Colours::black);
    otherLookAndFeel.setColour (ComboBox::arrowColourId,  Colours::black);
    saveButton.setLookAndFeel(&otherLookAndFeel);
    fileComp->setLookAndFeel(&otherLookAndFeel);
    
    portamentoToggle.setSliderStyle(Slider::SliderStyle::LinearVertical);
    portamentoToggle.setRange(-1, 1);
    portamentoToggle.setValue(-1);
    portamentoToggle.addListener(this);
    portamentoToggle.setLookAndFeel(&sliderToggle);
    addAndMakeVisible(&portamentoToggle);

    portamentoVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "portamento", portamentoSlider);
    portamentoToggleVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "portamentoToggle", portamentoToggle);
}

PresetLoader::~PresetLoader()
{
    saveButton.setLookAndFeel(nullptr);
    fileComp->setLookAndFeel(nullptr);
    
}

void PresetLoader::paint (Graphics& g)
{
    fileComp->setBounds(10, 15, 220, 20);
    saveButton.setBounds(10, 60,buttonSize-5, buttonSize-5);
    initButton.setBounds(50, 60,buttonSize-5, buttonSize-5);
    synthName.setBounds(60, 20,200, 100);
    
    licenseToLabel.setBounds(7.5, 70,230, 105);
    portamentoSlider.setBounds(0, 85,45, 45);
    portamentoToggle.setBounds(52.5, 90,20, 25);
    portamentoLabel.setBounds(39, 70,50, 105);
    g.setColour(Colours::black);
    Line<float> line (Point<float> (90, 52.5),
                      Point<float> (229, 52.5));
    Line<float> line2 (Point<float> (90, 87.5),
                      Point<float> (229, 87.5));
    Line<float> line3 (Point<float> (88, 52.5),
                       Point<float> (88, 87.5));
    Line<float> line4 (Point<float> (231, 52.5),
                       Point<float> (231, 87.5));
    g.drawLine (line, 2.0f);
    g.drawLine (line2, 2.0f);
    g.drawLine (line3, 2.0f);
    g.drawLine (line4, 2.0f);
    g.setColour(Colours::whitesmoke);
    for(int i = 0; i<15; i++){
        Line<float> line (Point<float> (90, 55+i*2.25),
                          Point<float> (229, 55+i*2.25));
        g.drawLine (line, 2.0f);
    }
}

void PresetLoader::resized()
{

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
    if(button->getName() == saveButton.getName()){
    auto fileToSave = File::createTempFile ("saveChooserDemo");

    if (fileToSave.createDirectory().wasOk())
    {
        fileToSave = fileToSave.getChildFile ("atlas.preset");
        fileToSave.deleteFile();
        
    }
    FileOutputStream outStream (fileToSave);
    
    if (outStream.openedOk()){
        outStream.setPosition(0);
        outStream.truncate();
        String xml =  processor.tree->state.toXmlString();;
       
        StringRef ext ("preset");
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
    else {
        processor.initializeSynth();
    }

   
}

void PresetLoader::sliderValueChanged(Slider* slider)
{
    if(slider->getValue() == 1.0 || slider->getValue() == -1.0){
        return;
    }
    else if(slider->getValue() > 0.5){
        slider->setValue(1.0);
    } else {
        slider->setValue(-1.0);
    }
}
                

void PresetLoader::buttonStateChanged(Button* button){
    
}
