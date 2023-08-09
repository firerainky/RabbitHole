cmake_minimum_required(VERSION 3.13.4)

project(TestInclude)

add_executable(${PROJECT_NAME} main.cpp)

set(LIB_NAME AdderLib)

add_subdirectory(${LIB_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_NAME})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)