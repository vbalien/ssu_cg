cmake_minimum_required(VERSION 3.10)

project(gluLookAt_example)
add_executable(${PROJECT_NAME} main.cc)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

if (MSVC)
  if("${CMAKE_VS_PLATFORM_NAME}" MATCHES "x64")
    file(COPY "${EXTERNAL_PATH}/freeglut/bin/x64/freeglut.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
    file(COPY "${EXTERNAL_PATH}/freeglut/bin/x64/freeglut.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
  else()
    file(COPY "${EXTERNAL_PATH}/freeglut/bin/freeglut.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
    file(COPY "${EXTERNAL_PATH}/freeglut/bin/freeglut.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
  endif()
endif()
