# ATLAS-06

A subtractive software synthesizer built using the JUCE framework. It currently builds to vst, vst3 and audio unit. This synthesizer is inspired by 80s synths and its signal flow is a mix of a Roland Juno-06 and Roland Juno-106. Installer included with repo. 

## Some Features:
* Create and Load presets
* Portamento
* Chorus
* PWM
* LFO and ADSR filters
* Pitch Bend

![Alt text](ATLAS-06-screenshot.png?raw=true "ATLAS-06")


## Build
git clone https://github.com/sbadon122/ATLAS-06-Synthesizer.git
cd ATLASE-06-Synthesizer
git submodule update --init --recursive
cmake -Bbuild  # mac man want cmake -Bbuild -GXcode
cmake --build build --config Release
