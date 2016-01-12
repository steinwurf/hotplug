#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <iostream>

boost::asio::io_service io_service;

void read_handle(boost::asio::posix::stream_descriptor* descriptor,
                 const boost::system::error_code& ec,
                 std::size_t bytes_read)
{
    if(!ec)
    {
        int file_descripter = descriptor.native_handle();
    }
    else
    {
        std::cout << << "there was an error" << std::endln;
    }
}

void watch_descriptor(boost::asio::io_service& ios, int file_descriptor)
{
    boost::asio::posix::stream_descriptor* descriptor =
        new boost::asio::posix::stream_descriptor();

    std::vector<char> buffer(0);
    descriptor->async_read_some(boost::asio::buffer(buffer, 0),
                                boost::bind(read_handle, descriptor, _1, _2));
}

int main(void)
{
    return 0;
}
