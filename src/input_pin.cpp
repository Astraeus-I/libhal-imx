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

#include <cstdint>

#include <libhal-imx/input_pin.hpp>

#include <libhal-imx/clock.hpp>
#include <libhal-imx/constants.hpp>
#include <libhal-imx/pin.hpp>
#include <libhal-imx/power.hpp>
#include <libhal-util/bit.hpp>

#include "gpio_reg.hpp"

namespace hal::imx {
result<input_pin> input_pin::get(std::uint8_t p_port,
                                 std::uint8_t p_pin,
                                 input_pin::settings p_settings)
{
  input_pin gpio(p_port, p_pin);
  HAL_CHECK(gpio.configure(p_settings));
  return gpio;
}

input_pin::input_pin(std::uint8_t p_port, std::uint8_t p_pin)
  : m_port(p_port)
  , m_pin(p_pin)
{
}

status input_pin::driver_configure(const settings& p_settings)
{
  power(peripheral::gpio0).on();

  bit::modify(gpio_reg[m_port]->direction).clear(pin_mask(m_pin));

  // Pin mask is used to control which pins are updated or not through the
  // pin, set, and clear registers. The mask bit corresponding to the pin must
  // be set to 0 for the pin to be enabled.
  bit::modify(gpio_reg[m_port]->mask).clear(pin_mask(m_pin));

  pin(m_port, m_pin)
    .function(0)
    .dac(false)
    .analog(false)
    .open_drain(false)
    .resistor(p_settings.resistor);

  return hal::success();
}

result<hal::input_pin::level_t> input_pin::driver_level()
{
  auto pin_value = bit::extract(pin_mask(m_pin), gpio_reg[m_port]->pin);

  return level_t{ .state = static_cast<bool>(pin_value) };
}
}  // namespace hal::imx
