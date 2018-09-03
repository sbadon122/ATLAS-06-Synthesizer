/*
  ==============================================================================

    VCA.cpp
    Created: 2 Sep 2018 9:59:37pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "VCA.h"

//==============================================================================
VCA::VCA(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    vcaSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    vcaSlider.setRange(0, 1.0f);
    vcaSlider.setValue(0.75f);
    vcaSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    vcaSlider.addListener(this);
    addAndMakeVisible(&vcaSlider);
    addAndMakeVisible(&vcaLabel);
    vcaLabel.attachToComponent(&vcaSlider, false);
    vcaLabel.setText("VCA", dontSendNotification);
    
    vcaVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "vca", vcaSlider);

}

VCA::~VCA()
{
}

void VCA::paint (Graphics& g)
{
  vcaSlider.setBounds(10, 30, 40, 100);
}

void VCA::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void VCA::sliderValueChanged(Slider* slider)
{
    
}
