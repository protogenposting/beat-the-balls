cmake_minimum_required(VERSION 3.30)
include(FetchContent)

project(beat-the-balls)

file(GLOB_RECURSE SourceFiles src/*)

add_executable(${PROJECT_NAME} ${SourceFiles})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

set(CMAKE_BINARY_DIR bin)

file(COPY assets DESTINATION assets)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.4)
set(GLFW_BUILD_DOCS
    OFF
    CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS
    OFF
    CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES
    OFF
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
  glew
  GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
  GIT_TAG master)
set(glew-cmake_BUILD_SHARED
    OFF
    CACHE BOOL "" FORCE)
set(ONLY_LIBS
    ON
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glew)

add_compile_definitions(GLM_ENABLE_EXPERIMENTAL)
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 1.0.1)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(
  stb
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_TAG master)
FetchContent_MakeAvailable(stb)

target_include_directories(${PROJECT_NAME} PUBLIC source/
                                        ${CMAKE_BINARY_DIR}/_deps/stb-src)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw libglew_static glm)

add_custom_command(
    TARGET ${PROJECT_NAME}
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets/
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)