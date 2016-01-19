// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once
#include <functional>
namespace hotplug
{
    class hotpluginfo
    {
    public:
        hotpluginfo();
        ~hotpluginfo();

        std::string get_action();
        void set_action(std::string action);
        std::string get_device();
        void set_device(std::string device);

    private:
        std::string m_action;
        std::string m_device;
    };
}
