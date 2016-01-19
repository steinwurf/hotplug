// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing
#include <platform/config.hpp>

#include "hotplug_cam.hpp"

#if defined(PLATFORM_LINUX)
    #include "handle_hotplug_linux.hpp"
#endif


namespace hotplug
{
    hotpluginfo::hotpluginfo()
    {
        m_action = "";
        m_device = "";
    }

    std::string hotpluginfo::get_action()
    {
        return m_action;
    }

    void hotpluginfo::set_action(std::string action)
    {
        m_action = action;
    }

    std::string hotpluginfo::get_device()
    {
        return m_device;
    }

    void hotpluginfo::set_device(std::string device)
    {
        m_device = device;
    }
}
