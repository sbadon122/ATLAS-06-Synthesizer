cmake_minimum_required(VERSION 3.10)

set(CMAKE_OSX_DEPLOYMENT_TARGET 10.11 CACHE STRING "Build for 10.11")
set(CMAKE_CXX_STANDARD 17)

project(ATLAS-06 VERSION 0.9.0 LANGUAGES CXX)

add_subdirectory(lib/JUCE)

execute_process(
  COMMAND git rev-parse --abbrev-ref HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the latest abbreviated commit hash of the working branch
execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_COMMIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

juce_add_plugin(ATLAS-06
    PRODUCT_NAME "ATLAS-06"
    COMPANY_NAME "ISLNDS dsp."  
    BUNDLE_ID "com.islndsdsp.ATLAS-06"
    PLUGIN_MANUFACTURER_CODE ISLN
    PLUGIN_CODE Atl6

    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    
    FORMATS AU VST3 Standalone
)
target_compile_features(ATLAS-06 PRIVATE cxx_std_17 )
juce_generate_juce_header( ATLAS-06 )

target_include_directories(ATLAS-06 
  PRIVATE
  Source
  lib/Maximilian/cpp/openFrameworks/ofxMaxim/libs
)

#configure_file(
#  ${CMAKE_SOURCE_DIR}/Source/version.cpp.in
#  ${CMAKE_BINARY_DIR}/generated/version.cpp
#)

target_sources(ATLAS-06 PRIVATE
   Source/ChorusEffect.cpp
   Source/SubOscillator.cpp
   Source/PitchBend.cpp
   Source/PitchRange.cpp
   Source/Cutoff.cpp
   Source/HPF.cpp
   Source/LFO.cpp
   Source/PresetLoader.cpp
   Source/Noise.cpp
   Source/VCA.cpp
   Source/LfoFilterEnvelope.cpp
   Source/LFOPitch.cpp
   Source/PWM.cpp
   Source/PolaritySwitch.cpp
   Source/FilterEnvelope.cpp
   Source/PluginProcessor.cpp
   Source/Chorus.cpp
   Source/PWMModeSwitch.cpp
   Source/SquareOscillator.cpp
   Source/Resonance.cpp
   Source/LFOPWM.cpp
   Source/PluginEditor.cpp
   Source/SawOscillator.cpp
   Source/Envelope.cpp

   lib/Maximilian/cpp/openFrameworks/ofxMaxim/libs/fft.cpp
   lib/Maximilian/cpp/openFrameworks/ofxMaxim/libs/maxiAtoms.cpp
   lib/Maximilian/cpp/openFrameworks/ofxMaxim/libs/maxiFFT.cpp
   lib/Maximilian/cpp/openFrameworks/ofxMaxim/libs/maxiMFCC.cpp
   lib/Maximilian/cpp/openFrameworks/ofxMaxim/libs/maximilian.cpp

   #lib/Maximilian/src/libs/maxiMFCC.cpp
   #lib/Maximilian/src/libs/maxiReverb.cpp
   #lib/Maximilian/src/libs/maxiSynths.cpp
   #lib/Maximilian/src/libs/fft.cpp
   #lib/Maximilian/src/libs/maxiConvolve.cpp
   #lib/Maximilian/src/libs/maxiBark.cpp
   #lib/Maximilian/src/libs/maxiAtoms.cpp
   #lib/Maximilian/src/libs/maxiFFT.cpp
   #lib/Maximilian/src/libs/maxiGrains.cpp
   #lib/Maximilian/src/maximilian.cpp
  # ${CMAKE_BINARY_DIR}/generated/version.cpp
)

target_compile_definitions(ATLAS-06 PUBLIC
    JUCE_ALLOW_STATIC_NULL_VARIABLES=0
    JUCE_STRICT_REFCOUNTEDPOINTER=1

    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_USE_CURL=0
    JUCE_WEB_BROWSER=0

    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_REPORT_APP_USAGE=0

    JUCE_ALSA=1
    JUCE_JACK=1
)

target_link_libraries(ATLAS-06 PRIVATE
  juce::juce_analytics
  juce::juce_audio_utils
  juce::juce_audio_basics
  juce::juce_audio_devices
  juce::juce_audio_processors
  juce::juce_blocks_basics
  juce::juce_box2d
  juce::juce_core
  juce::juce_dsp
  juce::juce_gui_basics
  juce::juce_gui_extra
  juce::juce_opengl
  juce::juce_video
)

# Build installers
get_target_property( OUTPUT_DIR ATLAS-06 RUNTIME_OUTPUT_DIRECTORY )
add_custom_target( installer-pkg )
add_dependencies( installer-pkg ATLAS-06 )
set( INSTALLER_DIR ${CMAKE_BINARY_DIR}/asset )
set( INSTALLER_BASENAME "ATLAS-06" )

if( APPLE )
  add_custom_command(
    TARGET installer-pkg
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory  ${INSTALLER_DIR}
    COMMAND hdiutil create ${INSTALLER_DIR}/${INSTALLER_BASENAME}-macos-${GIT_COMMIT_HASH}.dmg -ov -volname "${INSTALLER_BASENAME}-${GIT_COMMIT_HASH}" -fs HFS+ -srcfolder ${OUTPUT_DIR}
    )
elseif( UNIX )
  add_custom_command(
    TARGET installer-pkg
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory  ${INSTALLER_DIR}
    COMMAND ls -l ${OUTPUT_DIR}
    COMMAND cd ${OUTPUT_DIR} && tar cf "${INSTALLER_DIR}/${INSTALLER_BASENAME}-linux-${GIT_COMMIT_HASH}.tgz" "${INSTALLER_BASENAME}" "${INSTALLER_BASENAME}.vst3" 
    )
else()
  file( TO_NATIVE_PATH "${INSTALLER_DIR}/${INSTALLER_BASENAME}-win-${GIT_COMMIT_HASH}.zip" OUTPUT_ZIP )
  message( "Creating ${OUTPUT_ZIP}" )
  add_custom_command(
    TARGET installer-pkg
    POST_BUILD
    WORKING_DIRECTORY ${OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory  ${INSTALLER_DIR}
    COMMAND ls
    COMMAND powershell Compress-Archive 
             -DestinationPath "${OUTPUT_ZIP}"
             -Path "${INSTALLER_BASENAME}.exe" "," "${INSTALLER_BASENAME}.vst3" 
    )
endif()
