// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

#include <libhal-util/bit.hpp>

namespace hal::imx {
/// gpio peripheral register map
struct imx_gpio_t
{
  /// Offset: 0x000 Determine pin direction (0 == Input, 1 = Output) (R/W)
  volatile std::uint32_t direction;
  /// Offset: 0x004 - 0x00C
  std::array<std::uint32_t, 3> reserved0;
  /// Offset: 0x010 (R/W)
  volatile std::uint32_t mask;
  /// Offset: 0x014 Pin status and output control (R/W)
  volatile std::uint32_t pin;
  /// Offset: 0x018 Write 1 to this to set output pin as 1 (HIGH voltage) (R/W)
  volatile std::uint32_t set;
  /// Offset: 0x01C Write 1 to this to Set output pin to 0 (LOW voltage) (R/W)
  volatile std::uint32_t clear;
};

inline std::array gpio_reg{
  reinterpret_cast<imx_gpio_t*>(0x401B8000),  // GPIO1
  reinterpret_cast<imx_gpio_t*>(0x401BC000),  // GPIO2
  reinterpret_cast<imx_gpio_t*>(0x401C0000),  // GPIO3
  reinterpret_cast<imx_gpio_t*>(0x401C4000),  // GPIO4
  reinterpret_cast<imx_gpio_t*>(0x400C0000),  // GPIO5
  reinterpret_cast<imx_gpio_t*>(0x42000000),  // GPIO6
  reinterpret_cast<imx_gpio_t*>(0x42004000),  // GPIO7
  reinterpret_cast<imx_gpio_t*>(0x42008000),  // GPIO8
  reinterpret_cast<imx_gpio_t*>(0x4200C000),  // GPIO9
};

inline constexpr bit::mask pin_mask(std::uint8_t p_pin)
{
  return bit::mask{ .position = p_pin, .width = 1 };
}
}  // namespace hal::imx
