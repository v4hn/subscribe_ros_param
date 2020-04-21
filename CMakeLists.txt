cmake_minimum_required(VERSION 2.8.3)
project(subscribe_param)

add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS roscpp)

catkin_package()

include_directories(
 ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/subscribe_param.cpp)
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)
