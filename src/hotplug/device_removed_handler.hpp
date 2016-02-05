// Copyright (c) 2016, Steinwurf
// All rights reserved.

#include <functional>

struct device_remove_handler
{
    std::function<void(std::string, std::string)> m_callback;
    std::string m_action;
    std::string m_device;


    device_remove_handler(std::function<void(std::string, std::string)> callback,
                          std::string action,
                          std::string device): m_callback(callback),
                                               m_action(action),
                                               m_device(device)
    {

    }

    void operator ()()
    {
        m_callback(m_action, m_device);
    }
};
