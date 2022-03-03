CPP=g++
CPPFLAGS=-Wall -std=c++11 -g

main-cpp:
	$(CPP) $(CPPFLAGS) *.cpp -o main -lsqlite3
clean:
	rm -vf main *.o