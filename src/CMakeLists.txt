#
# Cmakelists.txt file in src directory
#

add_subdirectory("engine")

set(SRC_SOURCE_FILES 
main.cpp
test.h
test.cpp
ball.h
ball.cpp
rotator.cpp
rotator.h
)

add_executable(${PROJECT_NAME} ${SRC_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} engine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
