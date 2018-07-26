
# - Try to find Jack Audio Libraries
# libjack; libjackserver;
# Once done this will define
#  LIBJACK_FOUND - System has libjack.so
#  LIBJACK_INCLUDE_DIRS - The jack.h include directories
#  LIBJACK_LIBRARIES - The libraries needed to use jack

# Install jack on Ubuntu: apt-get install libjack-jackd2-dev
# Add user to audio group: usermod -a -G audio <yourUserName>

find_path(LIBJACK_INCLUDE_DIR
    NAMES
        jack/jack.h
    PATHS
        /usr/include
        /usr/local/include
        /opt/local/include
        "C:/Program Files (x86)/Jack/includes"
)

if(WIN AND CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(EXTENSION 64)
endif()

find_library(LIBJACK_libjack_LIBRARY
    NAMES
        libjack${EXTENSION} jack
    PATHS
        /usr/lib
        /usr/local/lib
        /opt/local/lib
        "C:/Program Files (x86)/Jack/lib"
        "C:/Program Files/Jack/lib"
)

find_library(LIBJACK_libjackserver_LIBRARY
    NAMES
        libjackserver${EXTENSION} jackserver
    PATHS
        /usr/lib
        /usr/local/lib
        /opt/local/lib
        "C:/Program Files (x86)/Jack/lib"
        "C:/Program Files/Jack/lib"
)

set(LIBJACK_LIBRARIES ${LIBJACK_libjack_LIBRARY} ${LIBJACK_libjackserver_LIBRARY} )
set(LIBJACK_LIBRARY ${LIBJACK_LIBRARIES})
set(LIBJACK_INCLUDE_DIRS ${LIBJACK_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBJACK_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(LIBJACK  DEFAULT_MSG
                                  LIBJACK_LIBRARY LIBJACK_INCLUDE_DIR)

if(LIBJACK_FOUND)
    message(STATUS "LIBJACK_FOUND at: " ${LIBJACK_INCLUDE_DIR})
else()
    message(STATUS "LIBJACK_FOUND is not set. If you need it, please install Jack Audio from http://www.jackaudio.org!")
endif()
