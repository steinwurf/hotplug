// Copyright (c) 2016, Steinwurf
// All rights reserved.

#include <cstdint>
#include <iostream>
#include <string>
#include <functional>
#include <gtest/gtest.h>

#include <hotplug/hotplug.hpp>

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

        plug.stop_hotplug();
        plug.join_thread();
    }
}

TEST(test_hotplug, invoke_api)
{
    hotplug::test_hotplug();
}
