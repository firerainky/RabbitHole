cmake_minimum_required(VERSION 3.13.4)

project(AdderLib)
add_library(${PROJECT_NAME} adder.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER adder.h)
install(TARGETS ${PROJECT_NAME} 
  LIBRARY DESTINATION lib 
  PUBLIC_HEADER DESTINATION include/${PROJECT_NAME})
