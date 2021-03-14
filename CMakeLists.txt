cmake_minimum_required(VERSION 3.10)

project(ssu_cg)

set(EXTERNAL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/external")

# Win32 Support
if (WIN32)
  set(GLUT_ROOT_PATH "${EXTERNAL_PATH}/freeglut")
  set(GLUT_INCLUDE_DIRS "${EXTERNAL_PATH}/freeglut/include")
  set(OPENGL_LIBRARY_DIR "${EXTERNAL_PATH}/freeglut/lib/x64")
  file(COPY "${EXTERNAL_PATH}/freeglut/bin/x64/freeglut.dll" DESTINATION ${CMAKE_BINARY_DIR}/Debug)
  file(COPY "${EXTERNAL_PATH}/freeglut/bin/x64/freeglut.dll" DESTINATION ${CMAKE_BINARY_DIR}/Release)
endif()

add_subdirectory(first_example)
add_subdirectory(teapot_example)
