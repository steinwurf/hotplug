// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#include "hotplug.hpp"


#include <iostream>

#include <boost/asio/io_service.hpp>
#include <platform/config.hpp>



#if defined(PLATFORM_LINUX)
    #include "handle_hotplug_linux.hpp"
#endif

void print_add_info(std::string device)
{
    std::cout << "add: " << device << std::endl;
}

void print_remove_info(std::string device)
{
    std::cout << "remove:" << device << std::endl;
}

namespace hotplug
{



    void start_hotplug(std::function<void(std::string)> add_callback,
                       std::function<void(std::string)> remove_callback)
    {
        boost::asio::io_service io;

        handle_hotplug_linux monitor = handle_hotplug_linux(io,
                                                            add_callback,
                                                            remove_callback);
        io.run();
        monitor.join_thread();
    }


}
