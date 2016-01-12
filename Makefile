all:
	g++ -c -std=c++11 hotplug_cam.cpp -ludev -I/usr/include/boost/asio/posix

test:
	g++ -std=c++11 test.cpp -ludev -lboost_system -lboost_thread
clean:
	rm *.o
