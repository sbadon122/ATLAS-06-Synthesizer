
#-------------------------------------------------------------------------------
# Run the validator after building
function(smtg_run_vst_validator target)
    add_dependencies(${target} validator)
    if(WIN)
        set(TARGET_PATH $<TARGET_FILE:${target}>)
        add_custom_command(TARGET ${target} 
            POST_BUILD COMMAND 
            $<TARGET_FILE:validator> 
            "${TARGET_PATH}" 
            WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
            )
    else()
        get_target_property(VST3_PACKAGE_PATH ${target} SMTG_VST3_PACKAGE_PATH)
        add_custom_command(TARGET ${target} 
            POST_BUILD COMMAND 
            $<TARGET_FILE:validator> 
            $<$<CONFIG:Debug>:${VST3_PACKAGE_PATH}>
            $<$<CONFIG:Release>:${VST3_PACKAGE_PATH}> 
            WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
        )
    endif()
endfunction()

#-------------------------------------------------------------------------------
# Strip symbols for Linux
function (smtg_strip_symbols target)
    add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND_STRIP} strip --strip-debug --strip-unneeded $<TARGET_FILE:${target}>
    )
endfunction()

# Strip symbols with debug file for Linux
function (smtg_strip_symbols_with_dbg target)
    add_custom_command(TARGET ${target} POST_BUILD
        # Create a target.so.dbg file with debug information
        COMMAND ${CMAKE_COMMAND_OBJECT_COPY} objcopy --only-keep-debug $<TARGET_FILE:${target}> $<TARGET_FILE:${target}>.dbg
        COMMAND ${CMAKE_COMMAND_STRIP} strip --strip-debug --strip-unneeded $<TARGET_FILE:${target}>
        COMMAND ${CMAKE_COMMAND_OBJECT_COPY} objcopy --add-gnu-debuglink=$<TARGET_FILE:${target}>.dbg $<TARGET_FILE:${target}>
    )
endfunction()

#-------------------------------------------------------------------------------
# Create symbolic link to VST3 folder
function (smtg_create_link_to_VST3 target)
    if(${SMTG_VST3_TARGET_PATH} STREQUAL "")
        message(FATAL_ERROR "Define a proper value for SMTG_VST3_TARGET_PATH")
    endif()

    get_target_property(TARGET_SOURCE ${target} SMTG_VST3_PACKAGE_PATH)
    get_target_property(TARGET_DESTINATION ${target} SMTG_VST3_USER_DEFINED_TARGET)
    if(WIN)
        FILE(TO_NATIVE_PATH "${TARGET_DESTINATION}" SRC_NATIVE_PATH)
        FILE(TO_NATIVE_PATH "${VST3_BINARY_DIR}/Debug/${VST3_PACKAGE_NAME}" TARGET_DESTINATION_DEBUG)
        FILE(TO_NATIVE_PATH "${VST3_BINARY_DIR}/Release/${VST3_PACKAGE_NAME}" TARGET_DESTINATION_RELEASE)

        add_custom_command(
            TARGET ${target} POST_BUILD
            COMMAND del "${SRC_NATIVE_PATH}"
            COMMAND mklink 
                 ${SRC_NATIVE_PATH}
                 $<$<CONFIG:Debug>:${TARGET_DESTINATION_DEBUG}>
                 $<$<CONFIG:Release>:${TARGET_DESTINATION_RELEASE}>
        )
    elseif(XCODE)
      add_custom_command(
          TARGET ${target} POST_BUILD
          COMMAND rm -f "${SRC_NATIVE_PATH}"
          COMMAND ln -sfF 
              "${TARGET_SOURCE}"
              "${TARGET_DESTINATION}"
      )
    else()
        add_custom_command(
            TARGET ${target} POST_BUILD
            COMMAND rm -f "${TARGET_DESTINATION}"
            COMMAND ln -sfF "${TARGET_SOURCE}" "${TARGET_DESTINATION}"
        )
    endif()
endfunction()

#-------------------------------------------------------------------------------
# VST3 Library Template
#-------------------------------------------------------------------------------
function(smtg_add_vst3plugin target sdkroot)
    set(sources ${ARGN})
    if(MAC)
        list(APPEND sources "${sdkroot}/public.sdk/source/main/macmain.cpp")
    elseif(WIN)
        list(APPEND sources "${sdkroot}/public.sdk/source/main/dllmain.cpp")
    elseif(LINUX)
        list(APPEND sources "${sdkroot}/public.sdk/source/main/linuxmain.cpp")
    endif()

    add_library(${target} MODULE ${sources})

       # Define all VST3 paths and directory names here which belong to the target.
    set(VST3_BINARY_DIR ${CMAKE_BINARY_DIR}/VST3)
    set(VST3_EXTENSION vst3)
    set(VST3_PACKAGE_NAME ${target}.${VST3_EXTENSION})
  
    set_target_properties(${target} PROPERTIES
                            LIBRARY_OUTPUT_DIRECTORY        ${VST3_BINARY_DIR}
                            SMTG_VST3_EXTENSION             ${VST3_EXTENSION}
                            SMTG_VST3_PACKAGE_NAME          ${VST3_PACKAGE_NAME}
                            SMTG_VST3_PACKAGE_CONTENTS      Contents
                            SMTG_VST3_PACKAGE_RESOURCES     Contents/Resources
                            SMTG_VST3_PACKAGE_SNAPSHOTS     Snapshots
                            SMTG_VST3_USER_DEFINED_TARGET   ${SMTG_VST3_TARGET_PATH}/${VST3_PACKAGE_NAME}
                            )

    target_compile_definitions(${target} PUBLIC $<$<CONFIG:Debug>:VSTGUI_LIVE_EDITING=1>)

    if(MAC)
        set_target_properties(${target} PROPERTIES BUNDLE TRUE)
        if(XCODE)
            set_target_properties(${target} PROPERTIES XCODE_ATTRIBUTE_GENERATE_PKGINFO_FILE "YES")
            set_target_properties(${target} PROPERTIES XCODE_ATTRIBUTE_WRAPPER_EXTENSION ${VST3_EXTENSION})
            set_target_properties(${target} PROPERTIES SMTG_VST3_PACKAGE_PATH      
                ${VST3_BINARY_DIR}/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>/${VST3_PACKAGE_NAME}
            )
        else()
            set_target_properties(${target} PROPERTIES BUNDLE_EXTENSION ${VST3_EXTENSION})
            set_target_properties(${target} PROPERTIES 
                                    LIBRARY_OUTPUT_DIRECTORY    ${VST3_BINARY_DIR}/${CMAKE_BUILD_TYPE}
                                    SMTG_VST3_PACKAGE_PATH      ${VST3_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${VST3_PACKAGE_NAME}
                                    )
        endif()
        smtg_set_exported_symbols(${target} "${sdkroot}/public.sdk/source/main/macexport.exp")

        target_link_libraries(${target} PRIVATE "-framework CoreFoundation")
        smtg_setup_universal_binary(${target})

    elseif(WIN)
        set_target_properties(${target} PROPERTIES SUFFIX ".${VST3_EXTENSION}")
        set_target_properties(${target} PROPERTIES LINK_FLAGS "/EXPORT:GetPluginFactory")
        set_target_properties(${target} PROPERTIES LINK_FLAGS_RELEASE "/EXPORT:GetPluginFactory /DEBUG:FASTLINK")
        set_target_properties(${target} PROPERTIES SMTG_VST3_PACKAGE_PATH      
                ${VST3_BINARY_DIR}/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>/${VST3_PACKAGE_NAME}
                )
        # Create Bundle on Windows
        if (SMTG_CREATE_BUNDLE_FOR_WINDOWS)
             if(WIN AND CMAKE_SIZEOF_VOID_P EQUAL 8)
                if(${CMAKE_GENERATOR} MATCHES "ARM")
                    set(PLATFORM_SUBFOLDER "arm_64-win")
                else()
                    set(PLATFORM_SUBFOLDER "x86_64-win")
                endif()
            else()
                 if(${CMAKE_GENERATOR} MATCHES "ARM")
                    set(PLATFORM_SUBFOLDER "arm-win")
                 else()
                    set(PLATFORM_SUBFOLDER "x86_64-win")
                endif()
            endif()

            get_target_property(VST3_PACKAGE_CONTENTS ${target} SMTG_VST3_PACKAGE_CONTENTS)
            set_target_properties(${target} PROPERTIES 
                                        LIBRARY_OUTPUT_DIRECTORY_DEBUG    ${VST3_BINARY_DIR}/Debug/${VST3_PACKAGE_NAME}/${VST3_PACKAGE_CONTENTS}/${PLATFORM_SUBFOLDER}
                                        LIBRARY_OUTPUT_DIRECTORY_RELEASE    ${VST3_BINARY_DIR}/Release/${VST3_PACKAGE_NAME}/${VST3_PACKAGE_CONTENTS}/${PLATFORM_SUBFOLDER}
                                  )
        endif()
        if(MSVC)
            target_compile_options(${target} PRIVATE /wd4221)
        endif()
    elseif(LINUX)
        # Modify the library output directory on Linux respecting the VST3 specification.
        EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE )
        set(target_lib_dir ${ARCHITECTURE}-linux)
        get_target_property(VST3_PACKAGE_CONTENTS ${target} SMTG_VST3_PACKAGE_CONTENTS)
        set_target_properties(${target} PROPERTIES PREFIX "")
        set_target_properties(${target} PROPERTIES 
                                    LIBRARY_OUTPUT_DIRECTORY    ${VST3_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${VST3_PACKAGE_NAME}/${VST3_PACKAGE_CONTENTS}/${target_lib_dir}
                                    SMTG_VST3_PACKAGE_PATH      ${VST3_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${VST3_PACKAGE_NAME}
                                    )

        # Create 'Resources' directory
        get_target_property(VST3_PACKAGE_PATH ${target} SMTG_VST3_PACKAGE_PATH)
        get_target_property(VST3_PACKAGE_RESOURCES ${target} SMTG_VST3_PACKAGE_RESOURCES)
        add_custom_command(TARGET ${target} PRE_LINK
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "${VST3_PACKAGE_PATH}/${VST3_RESOURCES_PATH}"
        )

        # Strip symbols in Release config
        if(${CMAKE_BUILD_TYPE} MATCHES Release)
            smtg_strip_symbols(${target})
        elseif(${CMAKE_BUILD_TYPE} MATCHES RelWithDebInfo)
            smtg_strip_symbols_with_dbg(${target})
        endif()
    endif()
    if(SMTG_RUN_VST_VALIDATOR)
        smtg_run_vst_validator(${target})
    endif()

    if(SMTG_CREATE_VST3_LINK)
        smtg_create_link_to_VST3(${target})
    endif()
endfunction()

# Add a resource for a target which gets copied into the targets Resource Bundle directory.
# @param target cmake target
# @param input_file resource file
# @param ARGV2 destination subfolder
function(smtg_add_vst3_resource target input_file)
    if (LINUX OR WIN)
        get_target_property(VST3_PACKAGE_PATH ${target} SMTG_VST3_PACKAGE_PATH)
        get_target_property(VST3_PACKAGE_RESOURCES ${target} SMTG_VST3_PACKAGE_RESOURCES)
        set(destination_folder "${VST3_PACKAGE_PATH}/${VST3_PACKAGE_RESOURCES}")
        if(ARGV2)
            set(destination_folder "${destination_folder}/${ARGV2}")
        endif()
        if(NOT EXISTS ${destination_folder})
          add_custom_command(TARGET ${target} PRE_LINK
              COMMAND ${CMAKE_COMMAND} -E make_directory
              "${destination_folder}"
          )
        endif()
        add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_CURRENT_LIST_DIR}/${input_file}"
            "${destination_folder}"
        )
    elseif(MAC)
        target_sources(${target} PRIVATE ${input_file})
        set(destination_folder "Resources")
        if(ARGV2)
            set(destination_folder "${destination_folder}/${ARGV2}")
        endif()
        set_source_files_properties(${input_file} PROPERTIES MACOSX_PACKAGE_LOCATION "${destination_folder}")
    endif()
endfunction()

# Add a snapshot for a target which gets copied into the targets Snapshot Bundle directory.
function(smtg_add_vst3_snapshot target snapshot)
    get_target_property(VST3_PACKAGE_SNAPSHOTS ${target} SMTG_VST3_PACKAGE_SNAPSHOTS)
    smtg_add_vst3_resource ("${target}" "${snapshot}" "${VST3_PACKAGE_SNAPSHOTS}") 
endfunction()
