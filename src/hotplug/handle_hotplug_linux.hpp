// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <functional>
#include <string>
#include <poll.h>
#include <libudev.h>

#include <iostream> // for test only


#include <thread>

#include "device_added_handler.hpp"
#include "device_removed_handler.hpp"

#include "handle_hotplug.hpp"


namespace hotplug
{

    class handle_hotplug_linux: public handle_hotplug
    {

    public:

        void init()
        {
            // create udev object
            m_hotplug = udev_new();
            if(!m_hotplug)
            {
                // throw exception
                // should be assert ?
            }

            // create the udev monitor
            m_hotplug_monitor = udev_monitor_new_from_netlink(m_hotplug, "udev");

            // start receiving hotplug events
            udev_monitor_enable_receiving(m_hotplug_monitor);
        }

        void deinit()
        {
            // destroy the udev monitor
            udev_monitor_unref(m_hotplug_monitor);

            // destroy the udev object
            udev_unref(m_hotplug);
        }

        void run(boost::asio::io_service& io)
        {
            // create the poll item
            pollfd items[1];
            items[0].fd = udev_monitor_get_fd(m_hotplug_monitor);
            items[0].events = POLLIN;
            items[0].revents = 0;

            // while there are hotplug events to process
            while(poll(items, 1, 50) > 0)
            {

                // receive the relevant device
                udev_device* dev = udev_monitor_receive_device(m_hotplug_monitor);
                if(!dev)
                {
                    // error receiving device, skip it
                    continue;
                }

                if(udev_device_get_action(dev) != NULL
                   && udev_device_get_devnode(dev) != NULL)
                {
                    std::string action = (std::string)udev_device_get_action(dev);
                    std::string device = (std::string)udev_device_get_devnode(dev);

                    if(((std::string)udev_device_get_action(dev)).compare("add") == 0)
                    {
                        device_added_handler dah = {m_add_callback, action, device};
                        io.post(dah);
                    }

                    if(((std::string)udev_device_get_action(dev)).compare("remove") == 0)
                    {
                        device_added_handler drh = {m_remove_callback,
                                                    ((std::string)udev_device_get_action(dev)),
                                                    ((std::string)udev_device_get_devnode(dev))};
                        io.post(drh);
                    }

                    udev_device_unref(dev);

                    // clear the revents
                    items[0].revents = 0;
                }
            }
        }

    private:
        udev* m_hotplug;
        udev_monitor* m_hotplug_monitor;
//        std::thread m_hotplug_thread;
    };
}
