project(min_line_distance)
cmake_minimum_required( VERSION 3.1 )

set( CMAKE_CXX_STANDARD 11 )
# add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_BUILD_TYPE Release )


set( OpenCV_DIR /usr/local/opencv4.2/lib/cmake/opencv4/)
find_package( OpenCV  REQUIRED)
set(min_line_distance_src	${CMAKE_CURRENT_SOURCE_DIR}/my_tracking_function.cpp
                            ${CMAKE_CURRENT_SOURCE_DIR}/my_tracking_function.h
                            ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
			#PARENT_SCOPE
)
add_executable(min_line_distance  ${min_line_distance_src})
target_link_libraries(min_line_distance PUBLIC ${OpenCV_LIBS})







