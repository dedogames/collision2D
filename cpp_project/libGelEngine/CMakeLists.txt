cmake_minimum_required(VERSION 3.0)

project("libGelEngine")
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)
SET(INSTALLATION_PATH ${CMAKE_BINARY_DIR}/Debug)

file(GLOB_RECURSE libGelEngine_SOURCES "src/*.cpp")
file(GLOB_RECURSE libGelEngine_HEADERS "src/*.hpp")

set(LIBRARIES_INCLUDE_PATH "usr/local/include")
set(LIBRARIES_PATH "/usr/loca/lib64")
set(LIBRARIES_LIB_PATH "/usr/local/lib")

foreach (_headerFile ${libGelEngine_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND libGelEngine_INCLUDE_DIRS ${_dir})
endforeach()
 
include_directories(src/include)
include_directories(/usr/local/include)

add_subdirectory(src)
 




 