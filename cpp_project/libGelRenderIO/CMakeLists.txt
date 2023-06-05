
 

cmake_minimum_required(VERSION 3.0)

project("libGelRender")
 
option(RENDER_LIB_TEST "Enable/Disable tests" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug) 
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

    add_subdirectory(test)
endif()


add_subdirectory(src)

add_subdirectory(extern/glad)
add_subdirectory(extern/glfw)
add_subdirectory(extern/imgui)

 
 