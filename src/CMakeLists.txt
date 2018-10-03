#
# Cmakelists.txt file in src directory
#

add_subdirectory("hearth")

set(SRC_SOURCE_FILES 
main.cpp
menu.h
menu.cpp
game.h
game.cpp
projectile.h
projectile.cpp
player.h
player.cpp
enemy.cpp
enemy.h
)

add_executable(${PROJECT_NAME} ${SRC_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} hearth ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
