#Engine CMakeLists.txt file


set(ENGINE_SOURCE_FILES 
    application.hpp
    application.cpp
    button.h
    button.cpp
    camera.h
    camera.cpp
    color.hpp
    collider.cpp
    collider.h
    collisionHandler.cpp
    collisionHandler.h
    error.cpp
    error.hpp 
    font.cpp
    font.h
    gameObject.cpp
    gameObject.hpp
    hearthData.h
    image.cpp
    image.h
    hObject.cpp
    hObject.h
    hTexture.h
    hTexture.cpp
    input.cpp
    input.hpp
    physics.cpp
    physics.h
    random.h
    random.cpp
    render.hpp
    render.cpp
    resourceManager.cpp
    resourceManager.hpp
    sprite.cpp
    sprite.hpp
    state.cpp
    state.hpp
    hTime.cpp
    hTime.h
    transform.cpp
    transform.h
    ui.h
    ui.cpp
    uiText.h
    uiText.cpp
    window.hpp
    window.cpp
)

add_library(hearth ${ENGINE_SOURCE_FILES})
