CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

PROJECT (MINGMU)

# CMake module path
SET (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
# destination paths
SET (MM_DATA_DIR ${CMAKE_INSTALL_PREFIX}/share/mingmu)
SET (MM_DOC_DIR ${CMAKE_INSTALL_PREFIX}/share/doc/mingmu)
# documents
SET (DOCS AUTHORS COPYING INSTALL NEWS README TODO)
# configure file
CONFIGURE_FILE (config.h.cmake ${CMAKE_SOURCE_DIR}/src/config.h)
# add subdirectories
ADD_SUBDIRECTORY (src bin)
# install files and directories
INSTALL (FILES ${DOCS} DESTINATION ${MM_DOC_DIR})
#INSTALL (DIRECTORY config/ DESTINATION ${MM_DATA_DIR})
