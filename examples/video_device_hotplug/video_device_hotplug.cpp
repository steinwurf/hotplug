// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing


#include <iostream>
#include <string>
#include <vector>

#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

#include <hotplug/hotplug.hpp>

int main(void)
{
    std::function<void(std::string)> add_callback = [](std::string add_string) {
        std::vector<std::string> info;
        boost::split_regex(info, add_string, boost::regex(","));

        std::cout << "Device: " << info[1] << " action: " << info[0];
    };

    std::function<void(std::string)> remove_callback = [](std::string remove_string) {
        std::vector<std::string> info;
        boost::split_regex(info, remove_string, boost::regex(","));

        std::cout << "Device: " << info[1] << " action: " << info[0];
    };

    hotplug::start_hotplug(add_callback, remove_callback);


    return 0;
}
