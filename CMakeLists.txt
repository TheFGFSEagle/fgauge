cmake_minimum_required(VERSION 3.1.0)
project(fgauge VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(BUILD_SHARED_LIBS ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(OpenGL_GL_PREFERENCE "GLVND")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH}")
set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS TRUE)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS UiTools REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenSceneGraph 3.6.0 REQUIRED
	osgSim
	osgDB
	osgParticle
	osgFX
	osgUtil
	osgViewer
	osgGA
)
find_package(osgQOpenGL REQUIRED)
add_subdirectory(3rdparty)
add_subdirectory(data)
add_subdirectory(src)

