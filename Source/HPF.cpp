/*
  ==============================================================================

    HPF.cpp
    Created: 2 Sep 2018 5:18:05pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "HPF.h"

//==============================================================================
HPF::HPF(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    hpfSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    hpfSlider.setRange(5.0f, 19000.0);
    hpfSlider.setValue(5.0f);
    hpfSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    hpfSlider.addListener(this);
    addAndMakeVisible(&hpfSlider);
    addAndMakeVisible(&hpfLabel);
    hpfLabel.attachToComponent(&hpfSlider, false);
    hpfLabel.setText("HPF", dontSendNotification);
    
    hfpVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "hpf", hpfSlider);

}

HPF::~HPF()
{
}

void HPF::paint (Graphics& g)
{
    hpfSlider.setBounds(50, 30, 40, 100);
}

void HPF::resized()
{
   
}

void HPF::sliderValueChanged(Slider* slider)
{
    
}
