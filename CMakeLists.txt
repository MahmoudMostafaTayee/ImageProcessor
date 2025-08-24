cmake_minimum_required(VERSION 3.28)

#set project name and version
project(ImageProcessor VERSION 0.1 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files.
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
set(SOURCES
	src/main.cpp
	src/ImageProcessor.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link external libraries
find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
	target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
endif()

# Place executable in project root (same level as images/ and output/)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Message summary
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Executable output directory: ${PROJECT_SOURCE_DIR}/bin")

