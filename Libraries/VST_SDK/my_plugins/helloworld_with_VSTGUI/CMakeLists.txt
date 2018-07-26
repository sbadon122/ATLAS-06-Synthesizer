
if(SMTG_ADD_VSTGUI)
    set(plug_sources
        include/plugcontroller.h
        include/plugids.h
        include/plugprocessor.h
        include/version.h
        source/plugfactory.cpp
        source/plugcontroller.cpp
        source/plugprocessor.cpp
    )

    #--- HERE change the target Name for your plug-in (for ex. set(target myDelay))-------
    set(target helloworldWithVSTGUI)

    smtg_add_vst3plugin(${target} ${SDK_ROOT} ${plug_sources})
    set_target_properties(${target} PROPERTIES ${SDK_IDE_MYPLUGINS_FOLDER})
    target_include_directories(${target} PUBLIC ${VSTGUI_ROOT}/vstgui4)
    target_link_libraries(${target} PRIVATE base sdk vstgui_support)

    smtg_add_vst3_resource(${target} "resource/plug.uidesc")
    smtg_add_vst3_resource(${target} "resource/background.png")
    smtg_add_vst3_resource(${target} "resource/animation_knob.png")
    smtg_add_vst3_resource(${target} "resource/onoff_button.png")
    smtg_add_vst3_resource(${target} "resource/background_2x.png")
    smtg_add_vst3_resource(${target} "resource/animation_knob_2x.png")
    smtg_add_vst3_resource(${target} "resource/onoff_button_2x.png")
    smtg_add_vst3_resource(${target} "resource/background_3x.png")
    smtg_add_vst3_resource(${target} "resource/animation_knob_3x.png")
    smtg_add_vst3_resource(${target} "resource/onoff_button_3x.png")

    smtg_add_vst3_snapshot(${target} "resource/41E3A6A2C1991743A64945DC3FB7D51D_snapshot.png")
    smtg_add_vst3_snapshot(${target} "resource/41E3A6A2C1991743A64945DC3FB7D51D_snapshot_2.0x.png")

    if(MAC)
        smtg_set_bundle(${target} INFOPLIST "${CMAKE_CURRENT_LIST_DIR}/resource/Info.plist" PREPROCESS)
    elseif(WIN)
        target_sources(${target} PRIVATE resource/plug.rc)
    endif()
endif(SMTG_ADD_VSTGUI)
