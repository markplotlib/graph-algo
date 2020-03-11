CPPFLAGS = -std=c++11 -Wall -Werror -pedantic -ggdb

graph.o : drivergraph.o Graph.o
	g++ $^ -o $@

%.o : %.cpp
	g++ $(CPPFLAGS) -c $< -o $@
