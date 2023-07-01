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

// TODO Needs to be updated to match the iMX RT 1060
#pragma once

#include <cstdint>

namespace hal::imx {
/// List of each peripheral and their power on id number for this platform
enum class peripheral : std::uint8_t
{
  gpio0 = 0,
  gpio1 = 1,
  gpio2 = 2,
  gpio3 = 3,
  gpio4 = 4,
  gpio5 = 5,
  gpio6 = 6,
  gpio7 = 7,
  gpio8 = 8,
  gpio9 = 9,
  gpio10 = 10,
  gpio11 = 11,
  gpio12 = 12,
  gpio13 = 13,
  gpio14 = 14,
  gpio15 = 15,
  gpio16 = 16,
  gpio17 = 17,
  gpio18 = 18,
  gpio19 = 19,
  gpio20 = 20,
  gpio21 = 21,
  gpio22 = 22,
  gpio23 = 23,
  gpio24 = 24,
  gpio25 = 25,
  gpio26 = 26,
  gpio27 = 27,
  gpio28 = 28,
  gpio29 = 29,
  gpio30 = 30,
  gpio31 = 31,
  i2c0 = 32,
  i2c1 = 33,
  spi0 = 34,
  spi1 = 35,
  uart0 = 36,
  uart1 = 37,
  lpuart0 = 38,
  lpuart1 = 39,
  usb1 = 40,
  sdhc1 = 41,
  adc1 = 42,
  dac1 = 43,
  pwm1 = 44,
  can1 = 45,
  can2 = 46,
  flexspi = 47,
  gpt1 = 48,
  gpt2 = 49,
  kpp = 50,
  pit = 51,
  rtc = 52,
  snvs_hp = 53,
  snvs_lp = 54,
  tsc = 55,
  usbhshost = 56,
  usbotg = 57,
  xbar1 = 58,
  xbar2 = 59,
  xbar3 = 60,
  max,
};

/// List of interrupt request numbers for this platform
enum class irq : std::uint32_t
{
  dma_ch0 = 0,
  dma_ch1 = 1,
  dma_ch2 = 2,
  dma_ch3 = 3,
  dma_ch4 = 4,
  dma_ch5 = 5,
  dma_ch6 = 6,
  dma_ch7 = 7,
  dma_ch8 = 8,
  dma_ch9 = 9,
  dma_ch10 = 10,
  dma_ch11 = 11,
  dma_ch12 = 12,
  dma_ch13 = 13,
  dma_ch14 = 14,
  dma_ch15 = 15,
  dma_error = 16,
  lpuart0_status = 17,
  lpuart0_error = 18,
  lpuart1_status = 19,
  lpuart1_error = 20,
  uart0_status = 21,
  uart0_error = 22,
  uart1_status = 23,
  uart1_error = 24,
  i2c0 = 25,
  i2c1 = 26,
  spi0 = 27,
  spi1 = 28,
  pit = 29,
  rtc_alarm = 30,
  rtc_seconds = 31,
  flexspi = 32,
  sdhc1 = 33,
  can1_message = 34,
  can1_bus_off = 35,
  can1_error = 36,
  can2_message = 37,
  can2_bus_off = 38,
  can2_error = 39,
  usb1_host = 40,
  usb1_device = 41,
  xbar1 = 42,
  xbar2 = 43,
  adc1 = 44,
  tsc = 45,
  gpt1 = 46,
  gpt2 = 47,
  pwm1_0 = 48,
  pwm1_1 = 49,
  pwm1_2 = 50,
  pwm1_3 = 51,
  pwm1_fault = 52,
  kpp = 53,
  rtc = 54,
  i2s1_tx = 55,
  i2s1_rx = 56,
  usbotg = 57,
  usbhshost = 58,
  enet_1588_timer = 59,
  enet_mac_transmit = 60,
  enet_mac_receive = 61,
  enet_mac_error = 62,
  enet_phy_interrupt = 63,
  sdhc0 = 64,
  sdhc2 = 65,
  max,
};
///
enum class error_t
{
  requires_usage_of_external_oscillator,
  baud_rate_impossible,
};
}  // namespace hal::imx
