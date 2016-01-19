// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <functional>

#include <boost/asio/io_service.hpp>

class handle_hotplug
{
public:
    virtual void init() = 0;
    virtual void deinit() = 0;
    virtual void run() = 0;
    virtual void execute_run() = 0;
    virtual void start_hotplug_monitoring() = 0;

protected:
    boost::asio::io_service m_io;
    std::function<void(std::string)> m_add_callback;
    std::function<void(std::string)> m_remove_callback;
};
