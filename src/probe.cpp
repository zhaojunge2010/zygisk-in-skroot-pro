#include <cstdio>
#include <unistd.h>
#include <time.h>
#include "kernel_module_kit_umbrella.h"

// Do not print, persist, or transmit the root key.
int skroot_module_main(const char*, const char*) {
    timespec now{};
    const int clock_status = clock_gettime(CLOCK_BOOTTIME, &now);
    const int written = std::printf(
        "[SKZygiskProbe] stage=entry version=0.1.0 pid=%ld uid=%ld "
        "clock_status=%d boot_seconds=%lld injection=disabled\n",
        static_cast<long>(getpid()), static_cast<long>(getuid()),
        clock_status, static_cast<long long>(now.tv_sec));
    const int flush_status = std::fflush(stdout);
    return written < 0 || flush_status != 0 ? 1 : 0;
}

SKROOT_MODULE_NAME("SKZygisk Entry Probe")
SKROOT_MODULE_VERSION("0.1.0")
SKROOT_MODULE_DESC("Entry/log probe only. No Zygote injection or Zygisk API.")
SKROOT_MODULE_AUTHOR("SKZygisk experimental")
SKROOT_MODULE_ID32("a56bbdf8c3574ea083e366e6056c7892")
