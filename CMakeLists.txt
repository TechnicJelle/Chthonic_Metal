cmake_minimum_required(VERSION 3.19)
project(Chthonic_Metal)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Chthonic_Metal src/main.cpp)

target_link_libraries(Chthonic_Metal PRIVATE sfml-graphics)
target_compile_features(Chthonic_Metal PRIVATE cxx_std_23)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Chthonic_Metal POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Chthonic_Metal> $<TARGET_FILE_DIR:Chthonic_Metal> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Chthonic_Metal)
