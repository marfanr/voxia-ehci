#include "ehci.hpp"
#include <ioforge/ioforge.hpp>

extern "C" void serial_printf(const char *fmt, ...);

void
EHCIModule::setup()
{
    auto s = []() { serial_printf("hello from lambda\n"); };
    s();
    serial_printf("hello world\n");
}

IoForgeModuleConstructor(EHCIModule)
