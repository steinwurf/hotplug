// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#include <thread>
#include <platform/config.hpp>

#if defined(PLATFORM_LINUX)
    #include "handle_hotplug_linux.hpp"
#endif

#include "hotpluginfo.hpp"

namespace hotplug
{

    hotpluginfo info = hotpluginfo();
    std::thread hotplug_montoring(start_hotplug_montoring, info);
}
