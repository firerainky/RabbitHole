cmake_minimum_required(VERSION 3.13.4)

add_library(${LIB_NAME} adder.cpp)
# target_include_directories(${LIB_NAME} PUBLIC ./)

# set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER adder.h)

# install(TARGETS ${PROJECT_NAME} 
#   LIBRARY DESTINATION lib 
#   PUBLIC_HEADER DESTINATION include/${PROJECT_NAME})
