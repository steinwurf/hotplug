#include <poll.h>
#include <libudev.h>
#include <stdexcept>
#include <iostream>
#include <string>

udev* hotplug;
udev_monitor* hotplug_monitor;



void init()
{
  // create the udev object
  hotplug = udev_new();
  if(!hotplug)
  {
    throw std::runtime_error("cannot create udev object");
  }

  // create the udev monitor
  hotplug_monitor = udev_monitor_new_from_netlink(hotplug, "udev");

  // start receiving hotplug events
  udev_monitor_enable_receiving(hotplug_monitor);
}

void deinit()
{
  // destroy the udev monitor
  udev_monitor_unref(hotplug_monitor);

  // destroy the udev object
  udev_unref(hotplug);
}

void run()
{
  // create the poll item
  pollfd items[1];
  items[0].fd = udev_monitor_get_fd(hotplug_monitor);
  items[0].events = POLLIN;
  items[0].revents = 0;

  // while there are hotplug events to process
  while(poll(items, 1, 50) > 0)
  {

    // receive the relevant device
    udev_device* dev = udev_monitor_receive_device(hotplug_monitor);
    if(!dev)
    {
      // error receiving device, skip it
      continue;
    }

    // print action type and device
    if(udev_device_get_action(dev) != NULL
       && udev_device_get_devnode(dev) != NULL)
    {
        if(((std::string)udev_device_get_devnode(dev)).find("/dev/video") == 0)
        {
            std::cout << udev_device_get_action(dev) << " - device: "
                      << udev_device_get_devnode(dev) << std::endl;;
        }
    }

    udev_device_unref(dev);

    // clear the revents
    items[0].revents = 0;
  }
}

int main(int args, char* argv[])
{
  init();

  while(true)
  {
    run();
  }

  deinit();
}
