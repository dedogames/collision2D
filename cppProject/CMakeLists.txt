cmake_minimum_required(VERSION 3.0)

project("collision2D_project")

 
SET(TEST ON CACHE BOOL "Indica se adicionará os testes")
 
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)
SET(INSTALLATION_PATH ${CMAKE_BINARY_DIR}/Debug)

file(GLOB_RECURSE collision2D_SOURCES "src/*.cpp")
file(GLOB_RECURSE collision2D_HEADERS "src/*.hpp")

set(LIBRARIES_INCLUDE_PATH "usr/local/include")
set(LIBRARIES_PATH "/usr/loca/lib64")
set(LIBRARIES_LIB_PATH "/usr/local/lib")

foreach (_headerFile ${collision2D_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND collision2D_INCLUDE_DIRS ${_dir})
endforeach()
FIND_PACKAGE( Boost 1.81 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

enable_testing()
FIND_PACKAGE(GTest)
include_directories(/usr/local/include)

add_executable(collision2D_exec ${collision2D_SOURCES} ${collision2D_HEADERS} )
TARGET_LINK_LIBRARIES(collision2D_exec LINK_PUBLIC ${Boost_LIBRARIES} ${GTEST_LIBRARIES} )

 




 