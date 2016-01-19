// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <string>
#include <functional>

namespace hotplug
{
    void start_hotplug(std::function<void(std::string)> add_callback,
                       std::function<void(std::string)> remove_callback);
}
