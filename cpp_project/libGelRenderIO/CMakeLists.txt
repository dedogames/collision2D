cmake_minimum_required(VERSION 3.0)

project("libGelRender")
 
option(RENDER_LIB_TEST "Enable/Disable tests" OFF)

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
 
if(${RENDER_LIB_TEST})
    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

foreach (_headerFile ${libGelRender_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND libGelRender_INCLUDE_DIRS ${_dir})
endforeach()
 

 

add_subdirectory(src)

add_subdirectory(extern/glad)
add_subdirectory(extern/glfw)
add_subdirectory(extern/imgui)


if(${RENDER_LIB_TEST})
    add_subdirectory(test)
endif()
 