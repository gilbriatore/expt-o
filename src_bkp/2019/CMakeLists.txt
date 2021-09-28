cmake_minimum_required(VERSION 3.1.0)

project(Expto_v.190420.0.4)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

# Find Qt Package
set(QTDIR $ENV{QTDIR})
set(CMAKE_PREFIX_PATH ${QTDIR})
find_package(Qt5 COMPONENTS Core Widgets Network Concurrent REQUIRED)

# Find Kinect Package
find_package(KinectSDK2 REQUIRED)


# Find OpenCV Package
option(OpenCV_STATIC OFF)
find_package(OpenCV REQUIRED)

# Find PCL Package
set(PCL_ROOT $ENV{PCL_ROOT})
find_package(PCL REQUIRED)

# Find VTK Package
set(VTK_DIR $ENV{VTK_DIR})
find_package(VTK REQUIRED)

# Load VTK Settings
include(${VTK_USE_FILE})

# Find GLEW Package
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

# Additional Include Directories
#include_directories(${Qt5Core_INCLUDE_DIRS})
#include_directories(${Qt5Widgets_INCLUDE_DIRS})
#include_directories(${Qt5Network_INCLUDE_DIRS})
#include_directories(${Qt5Concurrent_INCLUDE_DIRS})
include_directories(${KinectSDK2_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BUILD_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PCL_INCLUDE_DIRS})

# Preprocessor Definitions
add_definitions(${Qt5Core_DEFINITIONS})
add_definitions(${Qt5Widgets_DEFINITIONS})
add_definitions(${Qt5Network_DEFINITIONS})
add_definitions(${Qt5Concurrent_DEFINITIONS})
add_definitions(${PCL_DEFINITIONS})


# Tell CMake to create the executable
add_executable(
    ${PROJECT_NAME}
    Main.cpp Morris.qrc
    MainWindow.h MainWindow.cpp MainWindow.ui
    Utils.h Utils.cpp stdafx.h
    Kinect/KinectSensor.h Kinect/KinectSensor.cpp
    Kinect/KinectReader.h Kinect/KinectReader.cpp
    Kinect/KinectWriter.h Kinect/KinectWriter.cpp
    ctkRangeSlider.h ctkRangeSlider.cpp
    CenaArena.h CenaArena.cpp
    ItemArena.h ItemArena.cpp
    ArenaView.h ArenaView.cpp
    Buffer.h Common.h Constantes.h
    CircularBuffer.h
    SharedImageBuffer.h SharedImageBuffer.cpp
)


# Set Static Link Runtime Library
if(OpenCV_STATIC)
  foreach(flag_var
      CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
      CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
      CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
      CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if(${flag_var} MATCHES "/MD")
      string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endif()
  endforeach()
endif()

# Additional Library Directories
link_directories(${PCL_LIBRARY_DIRS})
link_directories(${KinectSDK2_LIBRARY_DIRS})
link_directories(${OpenCV_LIB_DIR})

# Additional Dependencies
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Network)
target_link_libraries(${PROJECT_NAME} Qt5::Concurrent)
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${KinectSDK2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})
target_link_libraries(${PROJECT_NAME} "C:/Program Files (x86)/Microsoft SDKs/Windows/v10.0A/lib/x64/freeglut.lib")

# Use the Widgets module from Qt 5
#target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

add_custom_target(Qt5CopyBinaries
  COMMAND ${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Cored.dll         ${CMAKE_BINARY_DIR}
  COMMAND ${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Guid.dll          ${CMAKE_BINARY_DIR}
  COMMAND ${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Widgetsd.dll      ${CMAKE_BINARY_DIR}
  COMMAND ${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Core.dll          ${CMAKE_BINARY_DIR}
  COMMAND ${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Gui.dll           ${CMAKE_BINARY_DIR}
  COMMAND ${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Widgets.dll       ${CMAKE_BINARY_DIR}
  COMMAND ${CMAKE_COMMAND} -E copy "C:/Program Files/OpenNI2/Redist/OpenNI2.dll"    ${CMAKE_BINARY_DIR}
  COMMAND ${CMAKE_COMMAND} -E copy "C:/opencv/build/x64/vc15/bin/opencv_world343.dll" ${CMAKE_BINARY_DIR}
  COMMAND ${CMAKE_COMMAND} -E copy "C:/opencv/build/x64/vc15/bin/opencv_world343d.dll" ${CMAKE_BINARY_DIR}
)

add_dependencies(${PROJECT_NAME} Qt5CopyBinaries)



#cmake_minimum_required(VERSION 3.1)

## Working
##set(BOOST_ROOT "C:/Boost/Boost1.63/root")
##set(EIGEN_ROOT "C/Eigen/Eigen3.05/root")
##set(OpenCV_DIR "C:/OpenCV/build")
##set(OpenCV_INCLUDE_DIRS "C:/OpenCV/build/include")
##set(VTK_DIR "C:/VTK/VTK-build-7.1.1")
##set(KINECT_MAKE "D:/Qt/CapturaMorris/src/Kinect")

#set(CMAKE_MODULE_PATH
#    ${CMAKE_CURRENT_SOURCE_DIR}
#    ${CMAKE_MODULE_PATH}
#    ${KINECT_MAKE}
#)

## Create Project
#project(ExptoBioterio)

## Set StartUp Project
#set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")

## Find Boost
#find_package(Boost COMPONENTS system filesystem REQUIRED)

## Find OpenGL
#find_package(OpenGL REQUIRED)
#include_directories(${OPENGL_INCLUDE_DIRS})
#link_directories(${OPENGL_LIBRARIES})

## Find Kinect v.2
#find_package(KinectSDK2 REQUIRED)

## Find OpenCV
#option(OpenCV_STATIC OFF)
#find_package(OpenCV REQUIRED)

## Required Viz Module
##if(OpenCV_FOUND)
##  if(NOT "opencv_viz" IN_LIST OpenCV_LIBS)
##    message(FATAL_ERROR "not found opencv_viz module.")
##  endif()
##endif()

## Set Static Link Runtime Library
#if(OpenCV_STATIC)
#  foreach(flag_var
#           CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
#           CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
#           CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
#           CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
#    if(${flag_var} MATCHES "/MD")
#      string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
#    endif()
#  endforeach()
#endif()

## Find PCL Package
#set(PCL_ROOT $ENV{PCL_ROOT})
#find_package(PCL 1.8.0)
##find_package(PCL 1.8.0 REQUIRED)

## Find VTK Package
##set(VTK_DIR $ENV{VTK_DIR})
#find_package(VTK REQUIRED)

## Find Qt Package
#set(QTDIR $ENV{QTDIR})
#set(CMAKE_PREFIX_PATH ${QTDIR})
#find_package(Qt5Widgets REQUIRED)


## Set Automatic MOC
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

## Generate MOC Code and UI Header
#qt5_wrap_cpp(MOC MainWindow.h)
#qt5_wrap_ui(UI_HEADER MainWindow.ui)

## Add Executable
#add_executable(${PROJECT_NAME}
#    Main.cpp Morris.qrc
#    MainWindow.h MainWindow.cpp MainWindow.ui
#    Utils.h Utils.cpp stdafx.h
#    Kinect/KinectSensor.h Kinect/KinectSensor.cpp
#    Kinect/KinectReader.h Kinect/KinectReader.cpp
#    Kinect/KinectWriter.h Kinect/KinectWriter.cpp
#    ctkRangeSlider.h ctkRangeSlider.cpp
#    CenaArena.h CenaArena.cpp
#    ItemArena.h ItemArena.cpp
#    ArenaView.h ArenaView.cpp
#    Buffer.h Common.h Constantes.h
#    CircularBuffer.h
#    SharedImageBuffer.h SharedImageBuffer.cpp
#)

## Additional Include Directories
#include_directories(${Boost_INCLUDE_DIRS})
#include_directories(${PCL_INCLUDE_DIRS})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#include_directories(${CMAKE_CURRENT_BINARY_DIR})
#include_directories(${KinectSDK2_INCLUDE_DIRS})
#include_directories(${OpenCV_INCLUDE_DIRS})

## Load VTK Settings
#include(${VTK_USE_FILE})

## Preprocessor Definitions
#add_definitions(${PCL_DEFINITIONS})

## Additional Library Directories
#link_directories(${PCL_LIBRARY_DIRS})
#link_directories(${KinectSDK2_LIBRARY_DIRS})
#link_directories(${OpenCV_LIB_DIR})

## Additional Dependencies
#target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
#target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} ${KinectSDK2_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
