cmake_minimum_required(VERSION 3.16)
project(GameEngine LANGUAGES C CXX)

# ===========================
# BASIC SETTINGS
# ===========================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/build)

# ===========================
# FIND PACKAGES
# ===========================
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(Threads REQUIRED)
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# ===========================
# INCLUDE DIRECTORIES
# ===========================
include_directories(
    ${CMAKE_SOURCE_DIR}/external/glad/include
    ${CMAKE_SOURCE_DIR}/external/glm
    ${CMAKE_SOURCE_DIR}/external/pybind11/include
    ${CMAKE_SOURCE_DIR}/src
)


# ===========================
# GLAD
# ===========================
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)
set_target_properties(glad PROPERTIES LINKER_LANGUAGE C)

# ===========================
# PYBIND11
# ===========================
add_subdirectory(external/pybind11)

# ===========================
# SOURCE FILES
# ===========================
file(GLOB_RECURSE ENGINE_SOURCES
    src/Engine/**/*.cpp
)
file(GLOB_RECURSE ENGINE_HEADERS
    src/Engine/**/*.h
)

# ===========================
# EXECUTABLE
# ===========================
add_executable(GameEngine
    src/main.cpp
    ${ENGINE_SOURCES}
    ${ENGINE_HEADERS}
)

# ===========================
# LINK LIBRARIES
# ===========================
target_link_libraries(GameEngine
    PRIVATE glad
    PRIVATE glfw
    PRIVATE pybind11::embed
    PRIVATE OpenGL::GL
    PRIVATE Threads::Threads
)


# ===========================
# INCLUDE FOR GAMEENGINE
# ===========================
target_include_directories(GameEngine PRIVATE ${CMAKE_SOURCE_DIR}/src)
