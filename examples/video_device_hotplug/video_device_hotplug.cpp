// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing


#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include <hotplug/hotplug.hpp>

int main(void)
{
    std::function<void(std::string, std::string)> single_callback =
        [](std::string action, std::string device){
        std::cout << "Action: "  << action << " device: " <<  device << std::endl;
    };

    boost::asio::io_service io;
    boost::asio::io_service::work work(io);

    hotplug::hotplug plug;

    plug.start_hotplug(io, single_callback, single_callback);

    io.run();
    std::cout << "john" << std::endl;
    plug.join_thread();
    return 0;
}
