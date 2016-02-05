// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing


#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include <hotplug/hotplug.hpp>

/// @example video_device_hotplug
///
/// This example show to use hotplug for registre if a video device is pluged in
/// or pluged out of the host device.


int main(void)
{
    std::function<void(std::string, std::string)> single_callback =
        [](std::string action, std::string device){

        if(device.find("video") != std::string::npos){
            std::cout << "Video device: "  << device <<
            " action performed: " <<  action << std::endl;
        }
    };

    boost::asio::io_service io;
    boost::asio::io_service::work work(io);

    hotplug::hotplug plug(io);
    plug.start_hotplug(single_callback, single_callback);
    io.run();
    plug.join_thread();
    return 0;
}
