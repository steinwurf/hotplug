#include "hotplug.hpp"
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




namespace hotplug
{

    static void test_hotplug()
    {
        std::function<void(std::string)> add_callback = [](std::string add_string){
            std::cout << "add action: "  << add_string << std::endl;
        }

        std::function<void(std::string)> remove_callback = [](std::string remove_string){
            std::cout << "remove action: "  << remove_string << std::endl;
        }

        start_hotplug(add_callback, remove_callback);
    }
}
