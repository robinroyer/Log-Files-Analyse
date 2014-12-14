CXX=g++ -std=c++11

analog: AppliAnalog.o URLData.o URLStats.o Graph.o
	$(CXX) -o  analog AppliAnalog.o URLData.o URLStats.o Graph.o

AppliAnalog.o: AppliAnalog.cpp AppliAnalog.h URLData.h Graph.o
	$(CXX) -c AppliAnalog.cpp

URLData.o: URLData.cpp URLData.h URLStats.h
	$(CXX) -c URLData.cpp

URLStats.o: URLStats.cpp URLStats.h
	$(CXX) -c URLStats.cpp

Graph.o: Graph.cpp Graph.h URLData.h
	$(CXX) -c Graph.cpp




#in order to clean old .o
clean:
	rm -rf *.o
