// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#include <hotplug/hotplug.hpp>

#include <cstdint>
#include <iostream>
#include <string>
#include <functional>
#include <gtest/gtest.h>

#include "../helper_functions.hpp"
#include "../reset_usb.h"




namespace hotplug
{

    static void test_hotplug()
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

        hotplug plug(io);
        std::cout << "john" << std::endl;
        plug.start_hotplug(single_callback, single_callback);
        io.run();

        //reset_usb("dev/video0");
        plug.stop_hotplug();
        plug.join_thread();
    }
}

TEST(test_hotplug, invoke_api)
{
    hotplug::test_hotplug();
}
