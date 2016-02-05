// Copyright (c) 2016, Steinwurf
// All rights reserved.

#include <functional>
#include <iostream>
#include <string>

#include <hotplug/hotplug.hpp>

/// @example usb_device_hotplug
///
/// This example show to use hotplug for registre if a usb device is pluged in
/// or pluged out of the host device.
int main(void)
{
    std::function<void(std::string, std::string)> add_callback =
        [](std::string /*action*/, std::string device)
        {
            std::cout << "The device: " << device << " has been added"
            << std::endl;
        };

    std::function<void(std::string, std::string)> remove_callback =
        [](std::string /*action*/, std::string device)
        {
            std::cout << "The device: " << device << " has been removed"
            << std::endl;
        };

    boost::asio::io_service io;
    boost::asio::io_service::work work(io);

    hotplug::hotplug plug(io);
    plug.start_hotplug(add_callback, remove_callback);
    io.run();
    plug.join_thread();
    return 0;
}
