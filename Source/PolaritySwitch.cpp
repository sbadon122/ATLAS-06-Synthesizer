/*
  ==============================================================================

    PolaritySwitch.cpp
    Created: 5 Dec 2018 3:33:10pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PolaritySwitch.h"

//==============================================================================
PolaritySwitch::PolaritySwitch(SynthFrameworkAudioProcessor& p):
processor(p)
{
    polarityModeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    polarityModeSlider.setRange(-1, 1);
    polarityModeSlider.setValue(1);
    polarityModeSlider.addListener(this);
    addAndMakeVisible(&polarityModeSlider);
    
    
    
    polarityModeVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "polarityMode", polarityModeSlider);
}

PolaritySwitch::~PolaritySwitch()
{
}

void PolaritySwitch::paint (Graphics& g)
{
    polarityModeSlider.setBounds(3, 60, 20, 30);
}

void PolaritySwitch::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void PolaritySwitch::sliderValueChanged(Slider* slider)
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
