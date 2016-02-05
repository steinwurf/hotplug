// Copyright (c) 2016, Steinwurf
// All rights reserved.

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

        void set_add_callback(std::function<void(std::string,
                                                 std::string)> add_callback)
        {
            m_add_callback = add_callback;
        }

        void set_remove_callback(
            std::function<void(std::string,
                               std::string)> remove_callback)
        {
            m_remove_callback = remove_callback;
        }

    protected:
        boost::asio::io_service m_io;
        std::function<void(std::string, std::string)> m_add_callback;
        std::function<void(std::string, std::string)> m_remove_callback;
    };
}
