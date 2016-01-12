
all:
	g++ -c -std=c++11 hotplug_cam.cpp -ludev -I/usr/include/boost/asio/posix

test: hotplug
	g++ -std=c++11 hotplug.o src/test.cpp -ludev -lboost_system -lboost_thread
hotplug:
	g++ -c -std=c++11 src/hotplug.cpp -ludev -lboost_system

clean:
	rm *.o
