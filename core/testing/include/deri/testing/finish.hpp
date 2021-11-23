/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#pragma once

namespace deri::testing {
/**
 * End testing and pass results from the OS to an external test monitor
 *
 * This can either be implemented through a special hardware device or through
 * communications channels to a system emulator or hypervisor.
 *
 * @note The test finisher is expected to stop emulation or halt the device.
 * Control should never return back to the system under test.
 *
 * @param[in] code exit code, 0 for success, non-zero for failure
 */
[[noreturn]] void finish(int code);
}
