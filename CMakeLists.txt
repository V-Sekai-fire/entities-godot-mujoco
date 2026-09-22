# SPDX-License-Identifier: Apache-2.0 OR MIT
cmake_minimum_required(VERSION 3.22)
project(godot_mujoco CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# godot-cpp comes from this repository's own manifest (default.xml), placed under
# thirdparty/. See that file for why it is a manifest entry and not a submodule.
set(GODOT_CPP_DIR "${CMAKE_SOURCE_DIR}/thirdparty/godot-cpp" CACHE PATH "godot-cpp checkout")
if(NOT EXISTS "${GODOT_CPP_DIR}/CMakeLists.txt")
  message(FATAL_ERROR
    "missing godot-cpp at ${GODOT_CPP_DIR}. From the repository root:\n"
    "  repo init -u https://github.com/V-Sekai-fire/entities-godot-mujoco -m default.xml\n"
    "  repo sync")
endif()

add_subdirectory("${GODOT_CPP_DIR}" godot-cpp EXCLUDE_FROM_ALL)

# MuJoCo is vendored as a subtree under third_party/mujoco (not a manifest entry
# or submodule): the code is copied in, so the build has no external pin. The
# physics now runs natively in this extension rather than in a RISC-V sandbox.
set(MUJOCO_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(MUJOCO_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(MUJOCO_BUILD_SIMULATE OFF CACHE BOOL "" FORCE)
set(MUJOCO_TEST_PYTHON_UTIL OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/mujoco" mujoco EXCLUDE_FROM_ALL)

add_library(godot_mujoco SHARED
  src/mujoco_physics_server.cpp
  src/register_types.cpp
)
target_include_directories(godot_mujoco PRIVATE "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(godot_mujoco PRIVATE godot-cpp mujoco)

if(WIN32)
  set(PLATFORM "windows")
elseif(APPLE)
  set(PLATFORM "macos")
else()
  set(PLATFORM "linux")
endif()
string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_LOWER)
if(BUILD_LOWER STREQUAL "debug")
  set(VARIANT "template_debug")
else()
  set(VARIANT "template_release")
endif()
set_target_properties(godot_mujoco PROPERTIES
  PREFIX "lib"
  OUTPUT_NAME "godot_mujoco.${PLATFORM}.${VARIANT}.x86_64"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/demo/addons/mujoco/bin"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/demo/addons/mujoco/bin"
)

# The proven core, re-checked natively against the Lean theorems.
enable_testing()
add_executable(mujoco_bridge_test src/mujoco_bridge_test.cpp)
target_include_directories(mujoco_bridge_test PRIVATE "${CMAKE_SOURCE_DIR}/src")
add_test(NAME bridge_core COMMAND mujoco_bridge_test)
