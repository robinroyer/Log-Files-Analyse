CXX=g++ -std=c++11

analog: AppliAnalog.o URLData.o
	$(CXX) -o  analog AppliAnalog.o URLData.o	

AppliAnalog.o: AppliAnalog.cpp AppliAnalog.h URLData.h
	$(CXX) -c AppliAnalog.cpp

URLData.o: URLData.cpp URLData.h
	$(CXX) -c URLData.cpp	




#in order to clean old .o
clean:
	rm -rf *.o
