cmake_minimum_required(VERSION 3.1.0)

project(ExptoINPI)

#set(BOOST_ROOT "C:/Program Files/boost")
#set(GLEW_INCLUDEDIR "C:/Program Files (x86)/Microsoft SDKs/Windows/v10.0A/include")
#set(GLEW_GLEW_LIBRARY "C:/Program Files (x86)/Microsoft SDKs/Windows/v10.0A/lib/x64/glew32s.lib")

# Startup settings
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

# Find Qt Package
#set(QTDIR $ENV{QTDIR})
#set(CMAKE_PREFIX_PATH ${QTDIR})

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

## Additional Include Directories
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

## Preprocessor Definitions
#add_definitions(${Qt5Core_DEFINITIONS})
#add_definitions(${Qt5Widgets_DEFINITIONS})
#add_definitions(${Qt5Network_DEFINITIONS})
#add_definitions(${Qt5Concurrent_DEFINITIONS})
add_definitions(${PCL_DEFINITIONS})

# Generate MOC code and UI header
#qt5_wrap_cpp(MOC MainWindow.h)
#qt5_wrap_ui(UI_HEADER MainWindow.ui)
#qt5_wrap_cpp(MOC widget/TrackingWidget.h)
#qt5_wrap_ui(UI_HEADER widget/TrackingWidget.ui)
#qt5_wrap_cpp(MOC widget/ClusteringWidget.h)
#qt5_wrap_ui(UI_HEADER widget/ClusteringWidget.ui)
#qt5_wrap_cpp(MOC widget/CaptureWidget.h)
#qt5_wrap_ui(UI_HEADER widget/CaptureWidget.ui)
#qt5_wrap_cpp(MOC widget/FileWidget.h)
#qt5_wrap_ui(UI_HEADER widget/FileWidget.ui)
#qt5_wrap_cpp(MOC widget/VideoWidget.h)
#qt5_wrap_ui(UI_HEADER widget/VideoWidget.ui)
#qt5_wrap_cpp(MOC widget/ClusteringOptionWidget.h)
#qt5_wrap_ui(UI_HEADER widget/ClusteringOptionWidget.ui)
#qt5_wrap_cpp(MOC widget/FilterOptionWidget.h)
#qt5_wrap_ui(UI_HEADER widget/FilterOptionWidget.ui)
#qt5_wrap_cpp(MOC widget/SegmentationOptionWidget.h)
#qt5_wrap_ui(UI_HEADER widget/SegmentationOptionWidget.ui)
#qt5_wrap_cpp(MOC widget/MinCutOptionWidget.h)
#qt5_wrap_ui(UI_HEADER widget/MinCutOptionWidget.ui)

# Prepare Executable
add_executable(
  ${PROJECT_NAME}
  main.cpp
  MainWindow.h
  MainWindow.cpp
  MainWindow.ui
  kinect/KinectSensor.hpp
  kinect/KinectTypes.hpp
  kinect/KinectCloud.hpp
  util/Logger.h
  util/Logger.cpp
  util/Defines.h
  util/MMF.hpp
  util/MMF.cpp
  track/RemoveNaNs.hpp
  track/Resampling.hpp
  track/Compression.hpp
  track/PassthroughFilter.hpp
  track/Reconstruction.hpp
  track/RANSAC.hpp
  track/Centroid.hpp
  track/Covariance.hpp
  track/RadiusOutlier.hpp
  track/EuclideanCluster.hpp
  track/ColorRegion.hpp
  widget/VideoQVTKOpenGLWidget.h
  widget/VideoQVTKOpenGLWidget.cpp
  widget/ClusteringWidget.h
  widget/ClusteringWidget.cpp
  widget/ClusteringWidget.ui
  widget/ClusteringOptionWidget.h
  widget/ClusteringOptionWidget.cpp
  widget/ClusteringOptionWidget.ui
  widget/TrackingWidget.h
  widget/TrackingWidget.cpp
  widget/TrackingWidget.ui
  widget/FileWidget.h
  widget/FileWidget.cpp
  widget/FileWidget.ui
  widget/CaptureWidget.h
  widget/CaptureWidget.cpp
  widget/CaptureWidget.ui
  widget/FilterOptionWidget.h
  widget/FilterOptionWidget.cpp
  widget/FilterOptionWidget.ui
  widget/MinCutOptionWidget.h
  widget/MinCutOptionWidget.cpp
  widget/MinCutOptionWidget.ui
  widget/SegmentationOptionWidget.h
  widget/SegmentationOptionWidget.cpp
  widget/SegmentationOptionWidget.ui
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
#target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Network)
target_link_libraries(${PROJECT_NAME} Qt5::Concurrent)
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${KinectSDK2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})
# target_link_libraries(${PROJECT_NAME} "C:/Program Files (x86)/Microsoft SDKs/Windows/v10.0A/lib/x64/freeglut.lib")

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
