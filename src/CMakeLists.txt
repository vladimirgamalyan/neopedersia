SET(SOURCES
	main.cpp
)

ADD_EXECUTABLE(neopedersia ${SOURCES} Ground.cpp Ground.h WorldPainter.h Point.cpp Point.h WorldObject.h Texture.h World.cpp World.h WorldPainterImpl.cpp WorldPainterImpl.h Painter.h PainterImpl.cpp PainterImpl.h Texture.cpp)

IF(MINGW)
    SET(MINGW32_LIBRARY mingw32 CACHE STRING "mwindows for MinGW")
    FIND_LIBRARY(SDL2MAIN_LIBRARY NAMES SDL2main)
    SET(SDL2PP_LIBRARIES ${MINGW32_LIBRARY} ${SDL2MAIN_LIBRARY} ${SDL2PP_LIBRARIES})
ENDIF(MINGW)

TARGET_LINK_LIBRARIES(neopedersia ${SDL2PP_LIBRARIES} )
