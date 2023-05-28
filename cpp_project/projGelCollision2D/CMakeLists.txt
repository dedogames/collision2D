cmake_minimum_required(VERSION 3.0)

project("projCollision2D")

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

foreach (_headerFile ${projCollision2D_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND projCollision2D_INCLUDE_DIRS ${_dir})
endforeach()
 
 
add_subdirectory(src)



# add_executable(projCollision2D_exec ${projCollision2D_SOURCES} ${projCollision2D_HEADERS} glfw imgui glad ${OPENGL_LIBRARIES} )
# TARGET_LINK_LIBRARIES(projCollision2D_exec LINK_PUBLIC ${Boost_LIBRARIES} ${GTEST_LIBRARIES} )

 




 