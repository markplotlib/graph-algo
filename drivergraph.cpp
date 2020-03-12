#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    string a = "a", b = "b";
	vector<string> verts{ a, b};
	Graph gg = Graph(verts);
	gg.addEdge(a, b);

	// cout << "Wgt btwn " << a << " and " << b << " is: "
		 // << gg.getEdge(a, b) << endl;

	// fail: add edge to non-existant vertex
	cout << "test: vertex lmnop" << endl;
	gg.addEdge(a, "lmnop");

	// adding edge of non-default value
	// gg.addEdge(a, b, 123);


	// cout << "Vertices: ";
    // vector<string> vertVector = g1.vertices();
    // vector<string>::iterator itr;
    // for (auto itr : vertVector)
        // cout << itr << " ";
    // cout << endl;

    return 0;
}
