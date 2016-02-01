// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <string>
#include <functional>

#include <boost/asio/io_service.hpp>
#include <platform/config.hpp>

#include "hotplug.hpp"

#if defined(PLATFORM_LINUX)
    #include "handle_hotplug_linux.hpp"
#endif

namespace hotplug
{
    void execute_run(handle_hotplug& hotplug_dev, boost::asio::io_service& io);
    void start_hotplug(std::function<void(std::string, std::string)> add_callback,
                       std::function<void(std::string, std::string)> remove_callback);
}
