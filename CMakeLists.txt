# Copyright 2023 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.15)

project(libhal-imx VERSION 0.0.1 LANGUAGES CXX)

find_package(libhal REQUIRED CONFIG)
find_package(libhal-util REQUIRED CONFIG)

add_library(libhal-imx 
src/output_pin.cpp
src/input_pin.cpp
src/pin.cpp
# src/power.cpp
)


target_include_directories(libhal-imx PUBLIC include)
target_compile_features(libhal-imx PRIVATE cxx_std_20)
target_compile_options(libhal-imx PRIVATE -Wall -Wextra)
target_link_libraries(libhal-imx PRIVATE
  libhal::libhal
  libhal::util
)

if(NOT BUILD_TESTING STREQUAL OFF)
  add_subdirectory(tests)
endif()

install(TARGETS libhal-imx)
