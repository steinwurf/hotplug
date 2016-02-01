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




namespace hotplug
{

    static void test_hotplug()
    {

        std::function<void(std::string, std::string)> single_callback =
            [](std::string action, std::string device){
            std::cout << "Action: "  << action << " device: " <<  device << std::endl;
        };

        start_hotplug(single_callback, single_callback);
    }

}

TEST(test_hotplug, invoke_api)
{
    hotplug::test_hotplug();
}
