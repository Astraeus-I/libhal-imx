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

#include <libhal-imx/output_pin.hpp>

namespace hal::imx {

hal::result<output_pin> output_pin::create()
{
  // Fill this out
  return output_pin();
}

hal::status output_pin::driver_configure(
  [[maybe_unused]] const settings& p_settings)
{
  // Fill this out
  return hal::success();
}

hal::result<hal::output_pin::set_level_t> output_pin::driver_level(
  [[maybe_unused]] bool p_high)
{
  // Fill this out
  return set_level_t{};
}

hal::result<hal::output_pin::level_t> output_pin::driver_level()
{
  // Fill this out
  return hal::output_pin::level_t{ .state = true };
}
}  // namespace hal::imx





// OLD version
/*

#include <libhal-imx/output_pin.hpp>

#include <cstdint>

#include <libhal-imx/pin.hpp>

#include "gpio_reg.hpp"

namespace hal::imx {

result<output_pin> output_pin::get(std::uint8_t p_port,
                                   std::uint8_t p_pin,
                                   output_pin::settings p_settings)
{
  output_pin gpio(p_port, p_pin);
  HAL_CHECK(gpio.driver_configure(p_settings));
  return gpio;
}

output_pin::output_pin(std::uint8_t p_port, std::uint8_t p_pin)
  : m_port(p_port)
  , m_pin(p_pin)
{
}

status output_pin::driver_configure(const settings& p_settings)
{
  bit::modify(gpio_reg[m_port]->direction).set(pin_mask(m_pin));

  pin(m_port, m_pin)
    .function(0)
    .dac(false)
    .analog(false)
    .open_drain(p_settings.open_drain)
    .resistor(p_settings.resistor);

  return hal::success();
}

result<output_pin::set_level_t> output_pin::driver_level(bool p_high)
{
  if (p_high) {
    bit::modify(gpio_reg[m_port]->pin).set(pin_mask(m_pin));
  } else {
    bit::modify(gpio_reg[m_port]->pin).clear(pin_mask(m_pin));
  }

  return set_level_t{};
}

result<output_pin::level_t> output_pin::driver_level()
{
  auto pin_value = bit::extract(pin_mask(m_pin), gpio_reg[m_port]->pin);

  return level_t{ .state = static_cast<bool>(pin_value) };
}
}  // namespace hal::imx
*/