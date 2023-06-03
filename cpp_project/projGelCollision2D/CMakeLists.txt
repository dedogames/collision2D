cmake_minimum_required(VERSION 3.0)

project("projCollision2D")

option(COLLISION2D_LIB_TEST "Enable/Disable tests" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)
SET(INSTALLATION_PATH ${CMAKE_BINARY_DIR}/Debug)

file(GLOB_RECURSE projCollision2D_SOURCES "src/*.cpp")
file(GLOB_RECURSE projCollision2D_HEADERS "src/*.hpp")

set(LIBRARIES_INCLUDE_PATH "usr/local/include")
set(LIBRARIES_PATH "/usr/loca/lib64")
set(LIBRARIES_LIB_PATH "/usr/local/lib")

if(${COLLISION2D_LIB_TEST})
    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

foreach (_headerFile ${projCollision2D_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND projCollision2D_INCLUDE_DIRS ${_dir})
endforeach()
 
 
add_subdirectory(src)


if(${COLLISION2D_LIB_TEST})
    add_subdirectory(test)
endif()


 



# add_executable(projCollision2D_exec ${projCollision2D_SOURCES} ${projCollision2D_HEADERS} glfw imgui glad ${OPENGL_LIBRARIES} )
# TARGET_LINK_LIBRARIES(projCollision2D_exec LINK_PUBLIC ${Boost_LIBRARIES} ${GTEST_LIBRARIES} )

 




 