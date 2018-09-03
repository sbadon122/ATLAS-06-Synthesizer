/*
  ==============================================================================

    SubOscillator.cpp
    Created: 3 Sep 2018 11:51:05am
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SubOscillator.h"

//==============================================================================
SubOscillator::SubOscillator(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    subOscSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    subOscSlider.setRange(0, 1);
    subOscSlider.setValue(0);
    subOscSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 0, 0);
    subOscSlider.addListener(this);
    addAndMakeVisible(&subOscSlider);
    addAndMakeVisible(&subOscLabel);
    subOscLabel.attachToComponent(&subOscSlider, false);
    subOscLabel.setText("Sub Osc", dontSendNotification);
    
    subOscVal = new AudioProcessorValueTreeState::SliderAttachment (*processor.tree, "subOsc", subOscSlider);


}

SubOscillator::~SubOscillator()
{
}

void SubOscillator::paint (Graphics& g)
{
     subOscSlider.setBounds(10, 30, 100, 100);
}

void SubOscillator::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void SubOscillator::sliderValueChanged(Slider* slider)
{
    
}
