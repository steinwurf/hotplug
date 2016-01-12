// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#include "hotplug_cam.hpp"

namespace hotplug
{
    udev* hotplug;
    udev_monitor* hotplug_monitor;

    boost::asio::posix::stream_descriptor get_stream_descriptor(boost::asio::io_service& ios)
    {
        hotplug = udev_new();
        if(!hotplug)
        {
            throw std::runtime_error("cannot create udev object");
        }

        // create the udev monitor
        hotplug_monitor = udev_monitor_new_from_netlink(hotplug, "udev");

        // start receiving hotplug events
        udev_monitor_enable_receiving(hotplug_monitor);

        boost::asio::posix::stream_descriptor desc =
            boost::asio::posix::stream_descriptor(ios);
        desc.assign(udev_monitor_get_fd(hotplug_monitor));
        return desc;
    }
}
