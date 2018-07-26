
include(SetupVST3LibraryDefaultPath)

# do not build VST 2 by default
option(SMTG_CREATE_VST2_VERSION "Create the VST2 version of AGain" OFF)

# use by default SMTG_ as prefix for ASSERT,...
option(SMTG_RENAME_ASSERT "Rename ASSERT to SMTG_ASSERT" ON)

# Add VSTGUI
option(SMTG_ADD_VSTGUI "Add VSTGUI Support" ON)

# Add VST3 Plug-ins Samples
option(SMTG_ADD_VST3_PLUGINS_SAMPLES "Add VST3 Plug-ins Samples to the solution" ON)

# Add VST3 Hosting Samples
option(SMTG_ADD_VST3_HOSTING_SAMPLES "Add VST3 Hosting Samples to the solution" ON)

# Create Symbolic Link for the VST3 Plug-ins
if(WIN)
    set(DEF_OPT_LINK OFF) # be sure to start visual with admin right when enabling this
else()
    set(DEF_OPT_LINK ON)
endif()
option(SMTG_CREATE_VST3_LINK "Create symbolic link for each VST3 plug-in in ${VST3_FOLDER_NAME} Folder (you need to have the Administrator right on Windows!)" ${DEF_OPT_LINK})

# Create Bundle on Windows for the VST3 Plug-ins
if(WIN)
    option(SMTG_CREATE_BUNDLE_FOR_WINDOWS "Create Bundle on Windows for the VST3 Plug-ins (New since 3.6.10!)" OFF)
endif()

# Run the Validator after each new compilation of VST3 plug-ins
option(SMTG_RUN_VST_VALIDATOR "Run VST validator on VST3 plug-ins" ON)

# Enable Sample audioHost (based on Jack Audio)
if (LINUX)
    option(SMTG_ENABLE_USE_OF_JACK "Enable Use of Jack" ON)
else()
    # not yet tested on Windows and Mac
    option(SMTG_ENABLE_USE_OF_JACK "Enable Use of Jack" OFF)
endif()

# here you can define the VST3 plug-ins folder (it will be created)
smtg_get_default_vst3_path(DEFAULT_VST3_FOLDER)
set(SMTG_VST3_TARGET_PATH "${DEFAULT_VST3_FOLDER}" CACHE PATH "Here you can redefine the VST3 plug-ins folder")
file(MAKE_DIRECTORY ${SMTG_VST3_TARGET_PATH})
if(EXISTS ${SMTG_VST3_TARGET_PATH})
    message(STATUS "SMTG_VST3_TARGET_PATH is set to : " ${SMTG_VST3_TARGET_PATH})
else()
    message(STATUS "SMTG_VST3_TARGET_PATH is not set!")
endif()

# Here you can add Your own VST3 plug-ins folder (by default we add the HelloWorld included in my_plugins folder)
set(SMTG_MYPLUGINS_SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../my_plugins" CACHE PATH "Here you can add Your VST3 plug-ins folder")

if(EXISTS ${SMTG_MYPLUGINS_SRC_PATH})
    message(STATUS "SMTG_MYPLUGINS_SRC_PATH is set to : " ${SMTG_MYPLUGINS_SRC_PATH})
else()
    message(STATUS "SMTG_MYPLUGINS_SRC_PATH is not set. If you want to add your own plug-ins folder, specify it!")
endif()
