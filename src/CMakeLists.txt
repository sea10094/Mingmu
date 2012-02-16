#
# Mingmu: Aria2 based GUI download manager.
# Author: Iven Hsu <ivenvd AT gmail.com>
#

#Put here CPPs
SET(MINGMU_SRCS
    main.cpp
)

SET(MINGMU_HDRS
)

#Put here QRC files to be Rcc-ed
SET(MINGMU_RCC
    resources.qrc
    ../ts/resources-ts.qrc
)

#include paths for vlmc
INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/src
  .
)

CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/cmake/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

#Put here UI files
SET(MINGMU_UIS
)

QT4_WRAP_UI(MINGMU_UIS_H ${MINGMU_UIS})
QT4_ADD_RESOURCES(MINGMU_RCC_SRCS ${MINGMU_RCC})
QT4_AUTOMOC(MINGMU_MOC_SRCS ${MINGMU_SRCS})

IF( MINGW )
    # resource compilation for MinGW
    ADD_CUSTOM_COMMAND( OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/icon.o
        COMMAND ${CMAKE_WINDRES} -I${CMAKE_SOURCE_DIR} -i${CMAKE_SOURCE_DIR}/cmake/icon.rc
        -o ${CMAKE_CURRENT_BINARY_DIR}/icon.o )
    SET(MINGMU_SRCS ${MINGMU_SRCS} ${CMAKE_CURRENT_BINARY_DIR}/icon.o)
    SET(LINK_FLAGS -Wl,-subsystem,windows)
ENDIF( MINGW )

IF(WIN32)
    SET(GUI_TYPE WIN32)
ENDIF(WIN32)

IF(APPLE)
    SET(GUI_TYPE MACOSX_BUNDLE)
    SET(MINGMU_SRCS ${MINGMU_SRCS} ../share/mingmu.icns)
    SET_SOURCE_FILES_PROPERTIES(../share/mingmu.icns PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources)
    SET(MACOSX_BUNDLE_ICON_FILE mingmu.icns)
ENDIF(APPLE)

ADD_EXECUTABLE(mingmu ${MINGMU_SRCS} ${MINGMU_MOC_SRCS} ${MINGMU_UIS_H} ${MINGMU_RCC_SRCS} )

# Add translations
ADD_DEPENDENCIES(mingmu translations)

# Link the target against the Qt libraries
TARGET_LINK_LIBRARIES(mingmu ${MINGMU_LIBS})

# Now we are done.

INSTALL(TARGETS mingmu
        BUNDLE  DESTINATION ${MINGMU_BIN_DIR}
        RUNTIME DESTINATION ${MINGMU_BIN_DIR})

ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_SOURCE_DIR}/bin/mingmu
    COMMAND ${CMAKE_COMMAND} copy ${CMAKE_CURRENT_SOURCE_DIR}/mingmu ${CMAKE_SOURCE_DIR}/bin/mingmu
    DEPENDS ${CMAKE_BINARY_DIR}/src/mingmu
)

ADD_DEFINITIONS(-W -Wall)

# Creates app bundle in /bin, uncomment #-dmg to create a dmg output 
IF( APPLE )
    ADD_CUSTOM_COMMAND(
        TARGET mingmu
        POST_BUILD
        COMMAND macdeployqt ${CMAKE_CURRENT_BINARY_DIR}/../bin/mingmu.app -no-plugins #-dmg
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Deploying the Qt Framework onto the bundle"
    )
ENDIF( APPLE )

