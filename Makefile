CPPFLAGS = -std=c++11 -Wall -Werror -pedantic -ggdb

hw8.o : Heap.o Driver.o Graph.o
	g++ $^ -o $@

%.o : %.cpp
	g++ $(CPPFLAGS) -c $< -o $@
