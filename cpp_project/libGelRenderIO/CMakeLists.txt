cmake_minimum_required(VERSION 3.0)

project("libGelRender")
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)
SET(INSTALLATION_PATH ${CMAKE_BINARY_DIR}/Debug)

file(GLOB_RECURSE libGelRender_SOURCES "src/*.cpp")
file(GLOB_RECURSE libGelRender_HEADERS "src/*.hpp")

set(LIBRARIES_INCLUDE_PATH "usr/local/include")
set(LIBRARIES_PATH "/usr/loca/lib64")
set(LIBRARIES_LIB_PATH "/usr/local/lib")

foreach (_headerFile ${libGelRender_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND libGelRender_INCLUDE_DIRS ${_dir})
endforeach()
 
 
include_directories(/usr/local/include)
include_directories(/src/include)
add_subdirectory(src)
add_subdirectory(extern/glad)
add_subdirectory(extern/glfw)
add_subdirectory(extern/imgui)




 