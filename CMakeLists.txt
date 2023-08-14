cmake_minimum_required(VERSION 3.13.4)

project(TestInclude VERSION 1.0)

option(USE_ADDER "Use adder library" OFF)
configure_file(RabbitConfig.h.in RabbitConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

if(USE_ADDER)
    set(LIB_NAME AdderLib)
    add_subdirectory(${LIB_NAME})
    list(APPEND EXTRA_LIBS ${LIB_NAME})
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/${LIB_NAME}")
    # target_include_directories(${PROJECT_NAME} PRIVATE ${LIB_NAME})
    # target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_NAME})
endif()

find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if (GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

# Check if glfw was initialized
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The git submodule for glfw was not initialized! Please run 'git submodule update --init' and try again.")
endif()
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} PRIVATE external/glfw/include ${PROJECT_BINARY_DIR} ${EXTRA_INCLUDES})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw ${EXTRA_LIBS})


install(TARGETS ${PROJECT_NAME} DESTINATION bin)