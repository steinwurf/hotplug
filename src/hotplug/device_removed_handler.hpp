// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#include <functional>

struct device_remove_handler
{
    std::function<void(string)> m_callback;
    std::string m_device;

    device_remove_handler(std::function<void(std::string)> callback,
                         std::string device): m_callback(callback),
                                              m_device(device)
    {

    }

    void operator ()()
    {
        m_callback(m_device);
    }
}
