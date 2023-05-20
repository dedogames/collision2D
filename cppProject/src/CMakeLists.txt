file(GLOB_RECURSE collision2D-exec_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE collision2D-exec_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

set (collision2D-exec_INCLUDE_DIRS "")
foreach (_headerFile ${collision2D-exec_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND collision2D-exec_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES collision2D-exec_INCLUDE_DIRS)

add_executable(collision2D-exec ${collision2D-exec_SOURCES} ${collision2D-exec_HEADERS})
target_include_directories(collision2D-exec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/")
set_target_properties(collision2D-exec PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${INSTALLATION_PATH}/)
install(TARGETS collision2D-exec DESTINATION bin)

set(collision2D-exec_TARGET_LIBRARIES
    ${CMAKE_THREAD_LIBS_INIT} #pthread 
    )
target_link_libraries(collision2D-exec ${collision2D-exec_TARGET_LIBRARIES})