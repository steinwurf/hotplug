// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#include "hotplug.hpp"

#include <thread>
#include <iostream>

//#include <boost/asio/io_service.hpp>
// #include <platform/config.hpp>

// #if defined(PLATFORM_LINUX)
//     #include "handle_hotplug_linux.hpp"
// #endif


namespace hotplug
{


    void execute_run(handle_hotplug& monitor, boost::asio::io_service& io)
    {
        monitor.init();
        while(true)
        {
            monitor.run(io);
        }
        monitor.deinit();
    }

    std::thread start_hotplug(boost::asio::io_service& io, std::function<void(std::string,
                                          std::string)> add_callback,
                       std::function<void(std::string,
                                          std::string)> remove_callback)
    {

#if defined(PLATFORM_LINUX)
        handle_hotplug_linux monitor;
#endif
        monitor.set_add_callback(add_callback);
        monitor.set_remove_callback(remove_callback);

        std::thread hotplug_thread([&]{execute_run(monitor, io);});

        return hotplug_thread;
    }


}
