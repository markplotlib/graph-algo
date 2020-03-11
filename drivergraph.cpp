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
	// g1.addVertex("b");
	// g1.addEdge("a", "b");

	string vtx = "a";
	if (g1.hasVertex(vtx))
		cout << "vertex " << vtx << " is found" << endl;
	else
		cout << "vertex " << vtx << " NOT found" << endl;
	vtx = "b";
	if (g1.hasVertex(vtx))
		cout << "vertex " << vtx << " is found" << endl;
	else
		cout << "vertex " << vtx << " NOT found" << endl;

	cout << "Vertices: ";
    vector<string> vertVector = g1.vertices();
    vector<string>::iterator itr;
    for (auto itr : vertVector)
        cout << itr << " ";
    cout << endl;
	
    return 0;
}
