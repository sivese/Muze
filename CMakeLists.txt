cmake_minimum_required(VERSION 3.10)
project(Muze)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB SRC_FILES 
    "src/*.cc" 
    "src/game/*.cc" 
    "src/core/*.cc"
)

add_executable(Muze main.cc ${SRC_FILES})

target_link_libraries(Muze ${SDL2_LIBRARIES} SDL2_image)
message(STATUS "SDL2_IMAGE_LIBRARIES = ${SDL2IMAGE_LIBRARY}")
