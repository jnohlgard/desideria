/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include "deri/bsp_init.hpp"

#include "deri/bsp/config.hpp"
#include "deri/bsp/console.hpp"
#include "deri/bsp/devices.hpp"
#include "deri/console.hpp"
#include "deri/soc/init.hpp"
#include "deri/span_literals.hpp"

using namespace deri::literals;

namespace deri::bsp {
void initUtime() {
  using TimerManager = config::TimerManagerConfig::TimerManager;
  auto &&utime_driver_config = config::utime.config;
  utime = TimerManager{utime_driver_config.init(),
                       TimerManager::Frequency{config::utime.tick_rate_hz}};
  auto module_clock =
      soc::rcu.timerFreq(static_cast<unsigned>(utime_driver_config.module_id));
  auto prescaler = module_clock / config::utime.tick_rate_hz;
  auto &&utime_dev = utime_driver_config.dev;
  using TimerDev = std::remove_cvref_t<decltype(utime_dev)>;
  if (prescaler > TimerDev::max_value) {
    // Panic!
  }
  utime_dev.setPrescaler(TimerDev::Count(prescaler));
  utime.init();
}

void init() {
  soc::init();
  initUtime();
  console_init();
  console.write(std::as_bytes("Board init done\n"_span));
}
}  // namespace deri::bsp
