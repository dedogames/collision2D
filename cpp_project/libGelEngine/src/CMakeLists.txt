file(GLOB_RECURSE libGelEngine_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp") 
file(GLOB_RECURSE libGelEngine_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp") 

 
set (libGelEngine_INCLUDE_DIRS "")
foreach (_headerFile ${libGelEngine_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND libGelEngine_INCLUDE_DIRS ${_dir})
endforeach()
 
list(REMOVE_DUPLICATES libGelEngine_INCLUDE_DIRS)

add_library(GelEngine ${libGelEngine_SOURCES} ${libGelEngine_HEADERS}  ${OPENGL_LIBRARIES}    )
target_include_directories(GelEngine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/")
set_target_properties(GelEngine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${INSTALLATION_PATH})
install(TARGETS GelEngine DESTINATION ${INSTALLATION_PATH})
 

set(libGelEngine_TARGET_LIBRARIES
    ${CMAKE_THREAD_LIBS_INIT} #pthread 
    )
target_link_libraries(GelEngine ${libGelEngine_TARGET_LIBRARIES} ${OPENGL_LIBRARIES})