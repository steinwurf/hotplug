// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <string>
#include <functional>
#include <thread>

#include <boost/asio/io_service.hpp>
#include <platform/config.hpp>

#if defined(PLATFORM_LINUX)
    #include "handle_hotplug_linux.hpp"
#endif

namespace hotplug
{
    class hotplug
    {
    public:
        hotplug(boost::asio::io_service& io);
        void start_hotplug(std::function<void(std::string,
                                              std::string)> add_callback,
                           std::function<void(std::string,
                                              std::string)> remove_callback);
        void stop_hotplug();
        void join_thread();
    private:
        void execute_run(handle_hotplug& hotplug_dev, boost::asio::io_service& io);

    private:
        bool m_running;
        std::thread m_hotplug_thread;
        boost::asio::io_service& m_io;
#if defined(PLATFORM_LINUX)
        handle_hotplug_linux m_monitor;
#endif

    };

}
