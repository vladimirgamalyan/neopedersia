set(SOURCES
	main.cpp
	Ground.cpp
	Ground.h
	WorldPainter.h
	worldObjects/WorldObject.h
	Texture.h World.cpp World.h
	WorldPainterImpl.cpp
	WorldPainterImpl.h
	Painter.h
	PainterImpl.cpp
	PainterImpl.h
	Texture.cpp
	Vec2.h
	worldObjects/Wall.cpp
	worldObjects/Wall.h
	worldObjects/WorldObject.cpp
	Rect.h
	worldObjects/Pony.cpp
	worldObjects/Pony.h
	worldObjects/TownHall.cpp
	worldObjects/TownHall.h
	PathFinder.cpp PathFinder.h
	micropather.cpp micropather.h
	Config.h
	worldObjects/WorldObjectId.h
	worldObjects/Cannon.cpp
	worldObjects/Cannon.h
	worldObjects/Cannonball.cpp
	worldObjects/Cannonball.h
	Vec2.cpp
	Color.h
	worldObjects/Mortar.cpp
	worldObjects/Mortar.h
	worldObjects/Mortarball.cpp
	worldObjects/Mortarball.h
	worldObjects/Machinegun.cpp
	worldObjects/Machinegun.h
	worldObjects/MachinegunBullet.cpp
	worldObjects/MachinegunBullet.h
)

add_executable(neopedersia ${SOURCES})
target_link_libraries(neopedersia ${COMMON_LIBRARIES} ${SDL2PP_LIBRARIES} )
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
