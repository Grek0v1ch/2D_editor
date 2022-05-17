cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(2D_editor)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "-g")

add_executable(2D_editor src/main.cpp
						 src/point/point.cpp 
						 src/point/point.hpp
						 src/segment/segment.cpp
						 src/segment/segment.hpp
						 src/triangle/triangle.cpp
						 src/triangle/triangle.hpp
						 src/quadrangle/quadrangle.cpp
						 src/quadrangle/quadrangle.hpp
						 src/ellipse/ellipse.cpp
						 src/ellipse/ellipse.hpp)