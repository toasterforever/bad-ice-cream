cmake_minimum_required(VERSION 3.26)
project(bad_ice_cream)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0135 NEW)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        ptsd

        URL         https://github.com/ntut-open-source-club/practical-tools-for-simple-design/archive/refs/tags/v0.2.zip

        # Or alternatively if you want to use a specific git commit instead of a release:
        # GIT_REPOSITORY  https://github.com/ntut-open-source-club/practical-tools-for-simple-design.git
        # GIT_TAG         <git_tag>

        SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/PTSD
)

FetchContent_MakeAvailable(ptsd)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES}
        include/MainCharacter.hpp
        include/Enemies.hpp
        include/Wall.hpp
        include/Ice.hpp
        src/MainCharacter.cpp
        src/Ice.cpp
        src/Enemies.cpp
        include/Floor.hpp
        src/Floor.cpp
        include/BackGround.hPP
        src/BackGround.cpp
        include/Button.hpp
        src/Button.cpp
        include/Fruit.hpp
        include/Namespace_Model.hpp
        src/Fruit.cpp
        include/TurnOffThings.hpp
        include/Picture.hpp
        src/Picture.cpp
        src/Wall.cpp
        include/BGM.hpp
        include/Text.hpp
        src/AutoMove.cpp
        src/NameSpace_Model.cpp
        src/FruitUpdate.cpp
        src/PhaseChange.cpp
        src/TurnOnLV.cpp
        src/CharacterUpdate.cpp
        include/CampFire.hpp
        src/CampFire.cpp
        include/Block.hpp
        src/Block.cpp
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE GA_RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/Resources")
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE GA_RESOURCE_DIR="${CMAKE_INSTALL_PREFIX}/Resources")
endif()

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${DEPENDENCY_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/PTSD/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
        SDL2::SDL2main
        PTSD
)
