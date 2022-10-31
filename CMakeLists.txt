cmake_minimum_required(VERSION 3.2)

project(video_pipe)

add_definitions(-DAPI_EXPORTS)
add_definitions(-pthread)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
SET(CMAKE_BUILD_TYPE “Release”)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -O0 -g  -Wfatal-errors -D_MWAITXINTRIN_H_INCLUDED")
set(CMAKE_MACOSX_RPATH 1)

#find_package(OpenCV REQUIRED)
include_directories("/usr/local/include/opencv4")
link_directories("/usr/local/lib")

include_directories(/usr/local/cuda/include)
link_directories(/usr/local/cuda/lib64)

include_directories(/home/baofengzan/TensorRT-8.0.3.4.Linux.x86_64-gnu.cuda-10.2.cudnn8.2/TensorRT-8.0.3.4/include)
link_directories(/home/baofengzan/TensorRT-8.0.3.4.Linux.x86_64-gnu.cuda-10.2.cudnn8.2/TensorRT-8.0.3.4/lib)

include_directories(${PROJECT_SOURCE_DIR}/nodes)

file(GLOB NODES "nodes/*.cpp")
file(GLOB INFERS_NODES "nodes/infers/*.cpp")
file(GLOB OSD_NODES "nodes/osd/*.cpp")
file(GLOB_RECURSE SORT_NODES "nodes/track/*.cpp")

file(GLOB OBJECTS "objects/*.cpp")
file(GLOB ELEMENTS_OBJECTS "objects/elements/*.cpp")
file(GLOB SHAPES_OBJECTS "objects/shapes/*.cpp")
file(GLOB BA "ba/*.cpp")
file(GLOB UTILS_ANALYSIS_BOARD "utils/analysis_board/*.cpp")
file(GLOB UTILS_LOG "utils/logger/*.cpp")
file(GLOB VEHICLE_MIAN "third_party/trt_vehicle/main/*.cpp")
file(GLOB VEHICLE_MODELS "third_party/trt_vehicle/models/*.cpp")
file(GLOB VEHICLE_UTIL "third_party/trt_vehicle/util/*.cpp")

add_library(video_pipe SHARED ${NODES} ${INFERS_NODES} ${OSD_NODES} ${OBJECTS} ${ELEMENTS_OBJECTS} ${SHAPES_OBJECTS} ${BA} ${UTILS_ANALYSIS_BOARD} ${VEHICLE_MIAN} ${VEHICLE_MODELS} ${VEHICLE_UTIL} ${UTILS_LOG} ${SORT_NODES})
target_link_libraries(video_pipe  opencv_core opencv_imgproc opencv_videoio opencv_imgcodecs opencv_dnn opencv_freetype opencv_highgui opencv_video)


add_executable(video_pipe_c main/main5.cpp)
target_link_libraries(video_pipe_c video_pipe opencv_core opencv_imgproc opencv_videoio opencv_imgcodecs opencv_dnn opencv_freetype opencv_highgui opencv_video nvinfer nvinfer_plugin cuda cublas cudart cudnn stdc++fs)



