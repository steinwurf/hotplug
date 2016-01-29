// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#include <string>

namespace hotplug
{
    bool is_correct_action(std::string expected, std::string input)
    {
        if(expected.compare(input) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    std::string get_action_string(std::string input)
    {
        return input.substr(0, input.find(","));
    }
}
