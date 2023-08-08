cmake_minimum_required(VERSION 3.13.4)

project(TestInclude)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} AdderLib)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)