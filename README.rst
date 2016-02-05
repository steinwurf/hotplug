=====
hotplug
=====

hotplug is a C++ library for detecting and acting on the events which occur when a usb deviced is plugged in or out.

.. contents:: Table of Contents:
   :local:

License
============
hotplug license is based on the BSD License. Please refer to the LICENSE.rst file for more details.

Requirements
============
**Common**

- Boost

**Linux**

- libudev

On Fedora/CentOS libudev is part of the package `systemd-devel` and on Debian the package is called `libudev-dev`



Callback methods
================
For usage in hotplug, you will need two callback functions, which each takes two arguments

1. action, to registre if it is a remove or added action, which are performed
2. device, to registre which device the action is performed upon

Both arguments must be of the type `std::string`

See the examples for reference on how to define the callback methods
