// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <stdexcept>
#include <iostream>

#include <libudev.h>

#include <boost/asio/posix/stream_descriptor.hpp>
namespace hotplug_cam
{
    boost::asio::posix::stream_descriptor get_stream_descriptor(boost::asio::io_service& ios);
}
