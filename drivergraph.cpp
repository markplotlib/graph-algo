#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	vector<Graph::Vertex> verts{ "a", "b", "c"};
	Graph gg = Graph(verts);
	gg.addEdge("a", "b");

	// fail: add edge to non-existant vertex
	cout << "Test: vertex 'lmnop'. Result: ";
	gg.addEdge("a", "lmnop");

	// adding edge of non-default value
	gg.addEdge("a", "c", 123);
	
	cout << "Vertices: ";
    vector<string> vertVector = gg.vertices();
    vector<string>::iterator itr;
    for (auto itr : vertVector)
		cout << itr << " ";
    cout << endl;

	// throws std::bad_alloc
	Graph::EdgeList edgesFromA = gg.outgoing("a");

    return 0;
}
