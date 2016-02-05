// Copyright (c) 2016, Steinwurf
// All rights reserved.

#include "hotplug.hpp"

#include <thread>
#include <iostream>
#include <cassert>

namespace hotplug
{

    hotplug::hotplug(boost::asio::io_service& io) : m_io(io)
    {

        m_running = true;
    }

    void hotplug::execute_run(handle_hotplug& monitor,
                              boost::asio::io_service& io)
    {
        monitor.init();
        while(m_running)
        {
             monitor.run(io);
        }
        monitor.deinit();
    }

    void hotplug::start_hotplug(std::function<void(std::string,
                                          std::string)> add_callback,
                                std::function<void(std::string,
                                          std::string)> remove_callback)
    {

        m_monitor.set_add_callback(add_callback);
        m_monitor.set_remove_callback(remove_callback);
        m_hotplug_thread = std::thread([&]{execute_run(m_monitor, m_io);});
    }

    void hotplug::stop_hotplug()
    {
        m_running = false;
    }

    void hotplug::join_thread()
    {
        m_hotplug_thread.join();
    }
}
