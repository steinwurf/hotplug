// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing


#include <iostream>
#include <string>
#include <vector>


#include <hotplug/hotplug.hpp>

int main(void)
{
    std::function<void(std::string, std::string)> single_callback =
        [](std::string action, std::string device){
        std::cout << "Action: "  << action << " device: " <<  device << std::endl;
    };

    hotplug::start_hotplug(single_callback, single_callback);


    return 0;
}
