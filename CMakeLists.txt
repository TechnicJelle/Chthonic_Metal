cmake_minimum_required(VERSION 3.19)
project(Chthonic_Metal)

set(CMAKE_CXX_STANDARD 23)

# Find SFML shared libraries
find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED
        )

add_executable(Chthonic_Metal src/main.cpp src/Engine/Scene.cpp src/Engine/Scene.hpp src/Engine/Game.cpp src/Engine/Game.hpp src/Scenes/MainMenu.cpp src/Scenes/MainMenu.hpp src/Engine/Random.hpp src/Engine/Button.cpp src/Engine/Button.hpp src/Engine/GameObject.cpp src/Engine/GameObject.hpp src/GameObjects/Fire.cpp src/GameObjects/Fire.hpp src/Engine/Utils.hpp)

# Copy assets folder to build directory
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Link executable to required SFML libraries
target_link_libraries(Chthonic_Metal sfml-graphics)

install(TARGETS Chthonic_Metal DESTINATION bin)

