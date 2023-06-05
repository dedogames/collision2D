cmake_minimum_required(VERSION 3.0)

project("libGelEngine")

option(GIL_LIB_TEST "Enable/Disable tests" OFF)
 
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


if(${GIL_LIB_TEST})
    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

foreach (_headerFile ${libGelEngine_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND libGelEngine_INCLUDE_DIRS ${_dir})
endforeach()
 
include_directories(src/include)
include_directories(/usr/local/include)

add_subdirectory(src)

if(${GIL_LIB_TEST})
    add_subdirectory(test)
endif()
 




 