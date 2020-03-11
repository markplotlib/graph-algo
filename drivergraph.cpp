#include "Graph.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {    
    cout << "Graph object." << endl;
    
	// graph of 1-arg ctor
	// vector<string> v1; v1.push_back("ijk"); Graph g0 = Graph(v1);

	Graph g1 = Graph();
	g1.addVertex("a");
	string x = "a", y = "a";
	cout << "Wgt btwn " << x << " and " << y << " is: " 
		 << g1.getEdge(x, y) << endl;

	// y = "z";
	// cout << "Wgt btwn " << x << " and " << y << " is: " 
		 // << g1.getEdge(x, y) << endl;

	y = "b";
	g1.addVertex(y);
	g1.addEdge(x, y, 123);
	cout << "Wgt btwn " << x << " and " << y << " is: " 
		 << g1.getEdge(x, y) << endl;

	// b does not lead to a
	// string tmp;
	// tmp = x; x = y; y = tmp;
	// cout << "Wgt btwn " << x << " and " << y << " is: " 
		 // << g1.getEdge(x, y) << endl;

	// g1.addEdge("a", "c");
	// g1.addVertex("c");
	// g1.addEdge("a", "c");

	cout << "Vertices: ";
    vector<string> vertVector = g1.vertices();
    vector<string>::iterator itr;
    for (auto itr : vertVector)
        cout << itr << " ";
    cout << endl;
	
    return 0;
}
