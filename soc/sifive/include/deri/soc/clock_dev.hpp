/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/function.hpp"
#include "deri/dev/clock.hpp"
#include "deri/dev/clock_sifive.hpp"
#include "deri/irq.hpp"
#include "deri/log.hpp"

namespace deri::log {
struct Clock;
struct Clock : public Config<Level::INFO> {};
}  // namespace deri::log

namespace deri::mmio {
extern dev::clock::PrciSifive PRCI;
}

namespace deri::soc {
class Clock {
  using Logger = log::Logger<log::Clock>;

 public:
  using OnClockChange = dev::clock::OnClockChange;
  enum class Core {};
  enum class TileLink {};

  using HfxoscConfig = deri::dev::clock::PrciSifive::HfxoscConfig;
  using HfroscConfig = deri::dev::clock::PrciSifive::HfroscConfig;
  using PllConfig = deri::dev::clock::PrciSifive::PllConfig;

  // Base frequency of the HFROSC oscillator.
  static constexpr unsigned hfrosc_center_freq = 72'000'000;

  [[nodiscard]] static unsigned current(Core) { return mmio::PRCI.coreFreq(); }
  [[nodiscard]] static unsigned current(TileLink) {
    return mmio::PRCI.tlFreq();
  }

  // The FE310 does not provide any module clock gating
  static void enable(TileLink) {}

  template <TileLink clock_bits>
  static void onClockChange(OnClockChange &on_clock_change) {
    arch::CriticalSection cs{};
    tlclk_users.remove(on_clock_change);
    tlclk_users.push_front(on_clock_change);
  }
  static void onClockChange(OnClockChange &on_clock_change, TileLink) {
    onClockChange<TileLink{}>(on_clock_change);
  }

  template <class Config>
  static void apply(const Config &config) {
    arch::CriticalSection cs{};
    Logger::info("Applying new clock config\n");
    mmio::PRCI.setConfig(config);
    auto tl_freq = current(TileLink{});
    for (const auto &on_clock_change : tlclk_users) {
      Logger::debug("onClockChange(tlclk %p: %lu)\n",
                    reinterpret_cast<const void *>(&on_clock_change),
                    static_cast<unsigned long>(tl_freq));
      on_clock_change.callback(tl_freq);
    }
    Logger::info("New clocks:\n");
    Logger::info(
        "Core = %u, tlclk = %u\n", current(Core{}), current(TileLink{}));
  }

 private:
  static inline ForwardList<OnClockChange> tlclk_users{};
};
}  // namespace deri::soc
