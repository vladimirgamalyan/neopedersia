PROJECT(neopedersia)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

# depends
IF(NOT EXISTS ${PROJECT_SOURCE_DIR}/extlibs/libSDL2pp/CMakeLists.txt)
	MESSAGE(FATAL_ERROR "The source directory\n  ${PROJECT_SOURCE_DIR}/extlibs/libSDL2pp\ndoes not contain a CMakeLists.txt file.\nIt is likely that you forgot to run\n  git submodule init && git submodule update")
ENDIF(NOT EXISTS ${PROJECT_SOURCE_DIR}/extlibs/libSDL2pp/CMakeLists.txt)

IF(WIN32)
set(CMAKE_PREFIX_PATH 
    "c:/usr/include"
	"c:/usr/lib"
    )
ELSE()
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic")
ENDIF()

SET(SDL2PP_WITH_IMAGE TRUE)
SET(SDL2PP_WITH_TTF TRUE)
ADD_SUBDIRECTORY(extlibs/libSDL2pp)

# datadir
#ADD_DEFINITIONS(-DDATADIR="${PROJECT_SOURCE_DIR}/data")

# sources
#SET(FIXME_PROJECT_SOURCES
#	main.cc
#)

#SET(FIXME_PROJECT_HEADERS
#)

# binary
INCLUDE_DIRECTORIES(SYSTEM ${SDL2PP_INCLUDE_DIRS})
#ADD_EXECUTABLE(FIXME_PROGNAME ${FIXME_PROJECT_SOURCES} ${FIXME_PROJECT_HEADERS})
TARGET_LINK_LIBRARIES(FIXME_PROGNAME ${SDL2PP_LIBRARIES})

ADD_SUBDIRECTORY(src)
