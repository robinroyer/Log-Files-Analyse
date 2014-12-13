CXX=g++ -std=c++11

analog: AppliAnalog.o
	$(CXX) -o analog AppliAnalog.o	

AppliAnalog.o: AppliAnalog.cpp AppliAnalog.h
	$(CXX)	 -c AppliAnalog.cpp

#in order to clean old .o
clean:
	rm -rf *.o
