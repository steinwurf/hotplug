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

    void start_hotplug(std::function<void(std::string)> add_callback,
                       std::function<void(std::string)> remove_callback)
    {
        boost::asio::io_service io;

#if defined(PLATFORM_LINUX)
        handle_hotplug_linux monitor;// = handle_hotplug_linux();
#endif
        monitor.set_add_callback(add_callback);
        monitor.set_remove_callback(remove_callback);

        std::thread hotplug_thread([&]{monitor.run(io);});
        execute_run(monitor, io);
        io.run();
        hotplug_thread.join();
    }


}
