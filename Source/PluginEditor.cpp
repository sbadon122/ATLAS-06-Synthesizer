/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), envGui(p), filterGui(p), resonanceGui(p), filterEnvelopeGui(p), lfoGui(p), lfoFilterEnvelopeGui(p), hpfGui(p), vcaGui(p), noiseGui(p), sawOscGui(p), squareOscGui(p), subOscGui(p), pitchRangeGui(p), pwmGui(p), lfoPitchGui(p), lfoPwmGui(p), chorusGui(p), keyboardComponent (p.keyboardState, MidiKeyboardComponent::horizontalKeyboard), presets(p), pwmModeSwitchGui(p), polaritySwitchGui(p), pitchBendGui(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 400);
    addAndMakeVisible(&envGui);
    addAndMakeVisible(&filterGui);
    addAndMakeVisible(&resonanceGui);
    addAndMakeVisible(&filterEnvelopeGui);
    addAndMakeVisible(&lfoGui);
    addAndMakeVisible(&lfoFilterEnvelopeGui);
    addAndMakeVisible(&hpfGui);
    addAndMakeVisible(&vcaGui);
    addAndMakeVisible(&noiseGui);
    addAndMakeVisible(&sawOscGui);
    addAndMakeVisible(&squareOscGui);
    addAndMakeVisible(&subOscGui);
    addAndMakeVisible(&pitchRangeGui);
    addAndMakeVisible(&pwmGui);
    addAndMakeVisible(&lfoPitchGui);
    addAndMakeVisible(&lfoPwmGui);
    addAndMakeVisible(&chorusGui);
    addAndMakeVisible(&keyboardComponent);
    addAndMakeVisible(&presets);
    addAndMakeVisible(&pwmModeSwitchGui);
    addAndMakeVisible(&polaritySwitchGui);
    addAndMakeVisible(&pitchBendGui);
    
    
    //Labels
    addAndMakeVisible(&lfoLabel);
    lfoLabel.setText ("LFO", dontSendNotification);
    lfoLabel.setJustificationType (Justification::centred);
    lfoLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&oscLabel);
    oscLabel.setText ("DCO", dontSendNotification);
    oscLabel.setJustificationType (Justification::centred);
    oscLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&envLabel);
    envLabel.setText ("ENV", dontSendNotification);
    envLabel.setJustificationType (Justification::centred);
    envLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&hpfLabel);
    hpfLabel.setText ("HPF", dontSendNotification);
    hpfLabel.setJustificationType (Justification::centred);
    hpfLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&envAmpLabel);
    envAmpLabel.setText ("VCF", dontSendNotification);
    envAmpLabel.setJustificationType (Justification::centred);
    envAmpLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&ampLabel);
    ampLabel.setText ("AMP", dontSendNotification);
    ampLabel.setJustificationType (Justification::centred);
    ampLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&chorusLabel);
    chorusLabel.setText ("CHORUS", dontSendNotification);
    chorusLabel.setJustificationType (Justification::centred);
    chorusLabel.setFont (Font (16.0f, Font::bold));
    
   
    //Styling LookAndFeel
    getLookAndFeel().setColour (TextButton::buttonColourId,  Colour(0xffe0dedf));
    getLookAndFeel().setColour (TextButton::buttonOnColourId,  Colour(0xffe0dedf));
    lfoGui.setLookAndFeel(&sliderLookAndFeel);
    lfoPwmGui.setLookAndFeel(&sliderLookAndFeel);
    pwmGui.setLookAndFeel(&sliderLookAndFeel);
    subOscGui.setLookAndFeel(&sliderLookAndFeel);
    noiseGui.setLookAndFeel(&sliderLookAndFeel);
    envGui.setLookAndFeel(&sliderLookAndFeel);
    hpfGui.setLookAndFeel(&sliderLookAndFeel);
    filterGui.setLookAndFeel(&sliderLookAndFeel);
    resonanceGui.setLookAndFeel(&sliderLookAndFeel);
    filterEnvelopeGui.setLookAndFeel(&sliderLookAndFeel);
    lfoFilterEnvelopeGui.setLookAndFeel(&sliderLookAndFeel);
    vcaGui.setLookAndFeel(&sliderLookAndFeel);
    pwmModeSwitchGui.setLookAndFeel(&sliderToggleLookAndFeel);
    polaritySwitchGui.setLookAndFeel(&sliderToggleLookAndFeel);
    
    
}


SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
    lfoGui.setLookAndFeel(nullptr);
    lfoPwmGui.setLookAndFeel(nullptr);
    pwmGui.setLookAndFeel(nullptr);
    subOscGui.setLookAndFeel(nullptr);
    noiseGui.setLookAndFeel(nullptr);
    envGui.setLookAndFeel(nullptr);
    hpfGui.setLookAndFeel(nullptr);
    filterGui.setLookAndFeel(nullptr);
    resonanceGui.setLookAndFeel(nullptr);
    filterEnvelopeGui.setLookAndFeel(nullptr);
    lfoFilterEnvelopeGui.setLookAndFeel(nullptr);
    vcaGui.setLookAndFeel(nullptr);
    pwmModeSwitchGui.setLookAndFeel(nullptr);
    polaritySwitchGui.setLookAndFeel(nullptr);
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colour(0xff333b3d));
    g.setColour(Colours::darkred);
    g.fillRect (3, 0, 120.5, 20);
    g.fillRect (127, 0, 462, 20);
    g.fillRect (593, 0, 204, 20);
    g.fillRect (3, 155, 83, 20);
    g.fillRect (91, 155, 257, 20);
    g.fillRect (352, 155, 116, 20);
    g.setColour(Colours::darkblue);
    g.fillRect (472, 155, 86, 20);
    g.setColour(Colours::darkred);
    g.fillRect (561, 155, 300, 20);
    g.setColour(Colour(0xff454a51));
     g.fillRect (0, 308, 800, 200);
    //g.fillRect (0, 308, 800, 6);
    g.setColour(Colours::whitesmoke);
    
    
    drawSquareLabel(402.5, 75, 1.8f, 1.4f, g);
    drawSawLabel(445, 75, 1.8f, 1.4f, g);
    drawDCOLabelLines(325, 30, 83, 1.4f, g);
    drawPolarityModeLabel(217, 233, 1.5f, 1.4f, false, g);
    drawPolarityModeLabel(217, 269, 1.5f, 1.4f, true, g);
    drawGateLabel(370, 285, 1.8f, 1.4f,  g);
    drawPolarityModeLabel(370, 223, 1.5f, 1.4f, false, g);
    drawEnvWhiteLabelLine(223, 215,  1.4f,  g);
    drawAmpWhiteLabelLine(375, 205,  1.4f,  g);
    drawSeparatingWhiteLines(lfoGui.getX()-4, lfoGui.getY(), lfoGui.getHeight()-5, 1.5f, g);
    drawSeparatingWhiteLines(lfoGui.getWidth()+lfoGui.getX()+5, lfoGui.getY(), lfoGui.getHeight()-5, 1.5f, g);
    drawSeparatingWhiteLines(noiseGui.getWidth()+noiseGui.getX(), noiseGui.getY(), noiseGui.getHeight()-5, 1.5f, g);
    drawSeparatingWhiteLines(envGui.getWidth()+envGui.getX()-6.5, envGui.getY(), envGui.getHeight()-5, 1.5f, g);
    drawSeparatingWhiteLines(hpfGui.getX()-4, hpfGui.getY(), hpfGui.getHeight()-3, 1.5f, g);
    drawSeparatingWhiteLines(hpfGui.getWidth()+hpfGui.getX()-6.5, hpfGui.getY()-3, hpfGui.getHeight(), 1.5f, g);
    drawSeparatingWhiteLines(lfoFilterEnvelopeGui.getWidth()+lfoFilterEnvelopeGui.getX(), lfoFilterEnvelopeGui.getY()-3, lfoFilterEnvelopeGui.getHeight(), 1.5f, g);
    drawSeparatingWhiteLines(vcaGui.getWidth()+vcaGui.getX(), vcaGui.getY()-3, vcaGui.getHeight(), 1.5f, g);
    drawSeparatingWhiteLines(chorusGui.getWidth()+chorusGui.getX(), chorusGui.getY()-3, chorusGui.getHeight(), 1.5f, g);
   
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();
    area.translate(5, 20);
    
    Rectangle<int> area2 = getLocalBounds();
    area2.translate(5, 175);
    
    //Labels
    lfoLabel.setBounds(10,5,100, 10);
    oscLabel.setBounds(140, 0, 440, 20);
    envLabel.setBounds(563, 0, 237, 20);
    hpfLabel.setBounds(15, 155, 57, 20);
    envAmpLabel.setBounds(91, 155, 259, 20);
    ampLabel.setBounds(352, 155, 103, 20);
    chorusLabel.setBounds(470, 155, 90, 20);
    
    //Synth Components
    lfoGui.setBounds(area.removeFromLeft(115).removeFromTop(140));
    pitchRangeGui.setBounds(area.removeFromLeft(127.5).removeFromTop(140));
    
    lfoPwmGui.setBounds(area.removeFromLeft(60).removeFromTop(140));
    pwmGui.setBounds(area.removeFromLeft(55).removeFromTop(140));
    pwmModeSwitchGui.setBounds(area.removeFromLeft(32.5).removeFromTop(140));
    squareOscGui.setBounds(area.removeFromLeft(40).removeFromTop(140));
    sawOscGui.setBounds(area.removeFromLeft(37.5).removeFromTop(140));
    subOscGui.setBounds(area.removeFromLeft(55).removeFromTop(140));
    noiseGui.setBounds(area.removeFromLeft(65).removeFromTop(140));
    envGui.setBounds(area.removeFromLeft(240).removeFromTop(140));
    hpfGui.setBounds(area2.removeFromLeft(90).removeFromTop(135));
    filterGui.setBounds(area2.removeFromLeft(55).removeFromTop(135));
    resonanceGui.setBounds(area2.removeFromLeft(60).removeFromTop(135));
    polaritySwitchGui.setBounds(area2.removeFromLeft(25).removeFromTop(135));
    filterEnvelopeGui.setBounds(area2.removeFromLeft(50).removeFromTop(135));
    lfoFilterEnvelopeGui.setBounds(area2.removeFromLeft(65).removeFromTop(135));
    vcaGui.setBounds(area2.removeFromLeft(120).removeFromTop(135));
    chorusGui.setBounds(area2.removeFromLeft(90).removeFromTop(135));
    presets.setBounds(area2.removeFromLeft(290).removeFromTop(135));
    
   

    //Keyboard
    keyboardComponent.setBounds(90, 315, 700, 85);
    pitchBendGui.setBounds(0, 315, 90, 85);
    
    
 
}

void SynthFrameworkAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
 
    
}

void SynthFrameworkAudioProcessorEditor::handleNoteOn(MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity)
{
 
}

void SynthFrameworkAudioProcessorEditor::handleNoteOff(MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity)
{

}

void SynthFrameworkAudioProcessorEditor::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{
   
}

void SynthFrameworkAudioProcessorEditor::drawSquareLabel(float x, float y, int size, float thickness, Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    float lineLength = 5.0f*size;
    double lineModifer = 1.5;
    Line<float> line (Point<float> (x, y),
                      Point<float> (x, y-lineLength));
    
    Line<float> line2 (Point<float> (x, y-lineLength),
                      Point<float> (x+lineLength, y-lineLength));
    
    Line<float> line3 (Point<float> (x+lineLength, y-lineLength),
                      Point<float> (x+lineLength, y));
    
    Line<float> line4 (Point<float> (x+lineLength, y),
                       Point<float> (x+lineLength+(lineLength*lineModifer), y));
    
    Line<float> line5 (Point<float> (x+lineLength+(lineLength*lineModifer), y),
                       Point<float> (x+lineLength+(lineLength*lineModifer), y-lineLength));
    
    g.drawLine (line, thickness);
    g.drawLine (line2, thickness);
    g.drawLine (line3, thickness);
    g.drawLine (line4, thickness/2);
    g.drawLine (line5, thickness);
    
    
}

void SynthFrameworkAudioProcessorEditor::drawSawLabel(float x, float y, int size, float thickness, Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    float lineLength = 5.0f*size;
    Line<float> line (Point<float> (x, y),
                      Point<float> (x, y-lineLength));
    
    Line<float> line2 (Point<float> (x, y-lineLength),
                       Point<float> (x+lineLength*2, y));
    
    g.drawLine (line, thickness);
    g.drawLine (line2, thickness);
    
}

void SynthFrameworkAudioProcessorEditor::drawDCOLabelLines(float x, float y, float width, float thickness, Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    Line<float> line (Point<float> (x, y),
                      Point<float> (x, y-5));
    
    Line<float> line2 (Point<float> (x, y-5),
                       Point<float> (x+width, y-5));
    
    Line<float> line3 (Point<float> (x+width, y-5),
                       Point<float> (x+width, y+30));
    
    Line<float> line4 (Point<float> (x+width * 0.6f, y-5),
                       Point<float> (x+width * 0.6f, y+45));
    
    
    g.drawLine (line, thickness);
    g.drawLine (line2, thickness);
    g.drawLine (line3, thickness);
    g.drawLine (line4, thickness);
    
}

void SynthFrameworkAudioProcessorEditor::drawSeparatingWhiteLines(float x, float y, float height, float thickness, Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    
    Line<float> line (Point<float> (x, y),
                     Point<float> (x, y+height));
    
    g.drawLine (line, thickness);
    
}

void SynthFrameworkAudioProcessorEditor::drawPolarityModeLabel(float x, float y, float size,  float thickness, Boolean flip, Graphics& g){
    g.setColour(Colours::whitesmoke);
    float lineLength = 5.0f*size;
    float tempY = flip ? y+lineLength : y-lineLength;
    float tempY2;
    Line<float> line (Point<float> (x, y),
                      Point<float> (x+lineLength*3/8, tempY));
    
    tempY2 = flip ? y+lineLength/2 : y-lineLength/2;
    Line<float> line2 (Point<float> (x+lineLength*3/8, tempY),
                      Point<float> (x+lineLength*6/8, tempY2));
    
    Line<float> line3 (Point<float> (x+lineLength*6/8, tempY2),
                       Point<float> (x+lineLength*6/8+lineLength/2, tempY2));
    
    Line<float> line4 (Point<float> (x+lineLength*6/8+lineLength/2, tempY2),
                       Point<float> (x+lineLength*1/2+lineLength, y));
  
    
    
    g.drawLine (line, thickness);
    g.drawLine (line2, thickness);
    g.drawLine (line3, thickness);
    g.drawLine (line4, thickness);
}

void SynthFrameworkAudioProcessorEditor::drawGateLabel(float x, float y, int size, float thickness, Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    float lineLength = 5.0f*size;
    Line<float> line (Point<float> (x, y),
                      Point<float> (x+lineLength*3/8, y));
    
    Line<float> line2 (Point<float> (x+lineLength*3/8, y),
                       Point<float> (x+lineLength*3/8, y-lineLength));
    
    Line<float> line3 (Point<float> (x+lineLength*3/8, y-lineLength),
                       Point<float> (x+lineLength*3/8+lineLength, y-lineLength));
    
    Line<float> line4 (Point<float> (x+lineLength*3/8+lineLength, y-lineLength),
                       Point<float> (x+lineLength*3/8+lineLength, y));
    
    Line<float> line5 (Point<float> (x+lineLength*3/8+lineLength, y),
                       Point<float> (x+lineLength*3/4+lineLength, y));
    
    g.drawLine (line, thickness);
    g.drawLine (line2, thickness);
    g.drawLine (line3, thickness);
    g.drawLine (line4, thickness);
    g.drawLine (line5, thickness);
    
    
}

void SynthFrameworkAudioProcessorEditor::drawEnvWhiteLabelLine(float x, float y,  float thickness, Graphics& g){
    g.setColour(Colours::whitesmoke);
    auto lineLength = 37.5f;
    Line<float> line (Point<float> (x, y),
                      Point<float> (x, y-lineLength*.8));
    
    Line<float> line2 (Point<float> (x, y-lineLength*.8),
                      Point<float> (x+lineLength*1.35, y-lineLength*.8));
    
    Line<float> line3 (Point<float> (x+lineLength*1.35, y-lineLength*.8),
                       Point<float> (x+lineLength*1.35, y-lineLength*.7));
    
    g.drawLine (line, thickness);
    g.drawLine (line2, thickness);
    g.drawLine (line3, thickness);
}

void SynthFrameworkAudioProcessorEditor::drawAmpWhiteLabelLine(float x, float y,  float thickness, Graphics& g){
    g.setColour(Colours::whitesmoke);
    auto lineLength = 27.5f;
    Line<float> line (Point<float> (x, y),
                      Point<float> (x, y-lineLength*.8));
    
    Line<float> line2 (Point<float> (x, y-lineLength*.8),
                       Point<float> (x+lineLength*1.75, y-lineLength*.8));
    
    Line<float> line3 (Point<float> (x+lineLength*1.75, y-lineLength*.8),
                       Point<float> (x+lineLength*1.75, y-lineLength*.7));
    
    g.drawLine (line, thickness);
    g.drawLine (line2, thickness);
    g.drawLine (line3, thickness);
}

