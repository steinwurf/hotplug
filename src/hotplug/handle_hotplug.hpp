// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <functional>

#include <boost/asio/io_service.hpp>

namespace hotplug
{
    class handle_hotplug
    {
    public:
        virtual void init() = 0;
        virtual void deinit() = 0;
        virtual void run(boost::asio::io_service& io) = 0;

        void set_add_callback(std::function<void(std::string)> add_callback)
        {
            m_add_callback = add_callback;
        }

        void set_remove_callback(std::function<void(std::string)> remove_callback)
        {
            m_remove_callback = remove_callback;
        }
        // virtual void execute_run(boost::asio::io_service& io) = 0;
        // virtual void start_hotplug_monitoring(boost::asio::io_service& io) = 0;

    protected:
        boost::asio::io_service m_io;
        std::function<void(std::string)> m_add_callback;
        std::function<void(std::string)> m_remove_callback;
    };
}
