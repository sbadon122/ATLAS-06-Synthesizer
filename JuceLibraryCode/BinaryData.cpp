/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== README ==================
static const unsigned char temp_binary_data_0[] =
"                      .__        .__.__  .__               \n"
"  _____ _____  ___  __|__| _____ |__|  | |__|____    ____  \n"
" /     \\\\__  \\ \\  \\/  /  |/     \\|  |  | |  \\__  \\  /    \\ \n"
"|  Y Y  \\/ __ \\_>    <|  |  Y Y  \\  |  |_|  |/ __ \\|   |  \\\n"
"|__|_|  (____  /__/\\_ \\__|__|_|  /__|____/__(____  /___|  /\n"
"      \\/     \\/      \\/        \\/                \\/     \\/ \n"
"\n"
"::::::::::::::::::::::::::What's Maximilian?\n"
"\n"
"Maximilian is an audio synthesis and signal processing library written in C++. It's cross-platform compatible with MacOS, Windows, Linux and IOS systems.  The main features are:\n"
"\n"
"- sample playback, recording and looping\n"
"- read from WAV and OGG files.\n"
"- a selection of oscillators and filters\n"
"- enveloping\n"
"- multichannel mixing for 1, 2, 4 and 8 channel setups\n"
"- controller mapping functions\n"
"- effects including delay, distortion, chorus, flanging\n"
"- granular synthesis, including time and pitch stretching\n"
"- atom synthesis\n"
"- realtime music information retrieval functions: spectrum analysis, spectral features, octave analysis, Bark scale analysis, and MFCCs\n"
"- example projects for Windows and MacOS, using command line and OpenFrameworks environments\n"
"\n"
"\n"
":::::::::::::::::::::::::::BASIC EXAMPLES\n"
"\n"
"You can choose between using RTAudio and PortAudio drivers in player.h by uncommenting the appropriate line.  To use PortAudio, you will need to compile the portAudio library from http://http://www.portaudio.com/ and link it with your executable.\n"
"\n"
"Examples demonstrating different features can be found in the maximilian_examples folder.  To try them, replace the contents of main.cpp with the contents of a tutorial file and compile.\n"
"\n"
"\n"
":::MAC OSX XCODE PROJECT\n"
"\n"
"You can run the examples using the 'maximilianTest' XCode 3 project provided.\n"
"\n"
"\n"
"::WINDOWS VISUAL STUDIO 2010 PROJECT\n"
"\n"
"This is in the maximilianTestWindowsVS2010 folder. You will need to install the DirectX SDK, so that the program can use DirectSound.\n"
"\n"
"\n"
":::COMMAND LINE COMPILATION IN MACOSX\n"
"\n"
"> g++ -Wall -D__MACOSX_CORE__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp -framework CoreAudio -framework CoreFoundation -lpthread\n"
"\n"
"> ./maximilian\n"
"\n"
"\n"
"::COMMAND LINE COMPILATION IN LINUX\n"
"\n"
"With OSS:\n"
"> g++ -Wall -D__LINUX_OSS__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp -lpthread\n"
"\n"
"With ALSA:\n"
"> g++ -Wall -D__LINUX_ALSA__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp -lasound -lpthread\n"
"\n"
"With Jack:\n"
"> g++ -Wall -D__UNIX_JACK__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp `pkg-config --cflags --libs jack` -lpthread\n"
"\n"
"then:\n"
"> ./maximilian\n"
"\n"
"\n"
"\n"
":::::::::::::::::::::::::::OPENFRAMEWORKS\n"
"\n"
"Maximilian works well with the OpenFrameworks C++ creative coding toolkit (http://www.openframeworks.cc).\n"
"\n"
"In the ofxMaxim directory you will find examples to run in Windows, OSX and iOS, including FFT analysis and granular synthesis.  \n"
"\n"
"You can install the ofxMaxim addon by copying the ofxMaxim/ofxMaxim folder into your openframeworks addons directory.\n"
"\n"
"Important: when using Maximilian on OSX, link against the Accelerate framework.\n";

const char* README = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x8fd84dae:  numBytes = 3042; return README;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "README"
};

const char* originalFilenames[] =
{
    "README"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
