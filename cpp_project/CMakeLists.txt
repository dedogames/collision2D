cmake_minimum_required(VERSION 3.20)

include_directories(libGelEngine/src/include)
include_directories(libGelRenderIO/src/include)
#Add projects
add_subdirectory(libGelEngine)
add_subdirectory(libGelRenderIO)
add_subdirectory(projGelCollision2D)


 