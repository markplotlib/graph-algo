#include "Graph.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Graph object." << endl;

	vector<string> verts;
    string x = "a", y = "b", z = "c";
	verts.push_back(x);
	verts.push_back(y);
	verts.push_back(z);
	Graph g1 = Graph(verts);

	cout << "Wgt btwn " << x << " and " << y << " is: "
		 << g1.getEdge(x, y) << endl;

	y = "b";
	g1.addEdge(x, y, 123);
	cout << "Wgt btwn " << x << " and " << y << " is: "
		 << g1.getEdge(x, y) << endl;

	// b does not lead to a
	// string tmp;
	// tmp = x; x = y; y = tmp;
	// cout << "Wgt btwn " << x << " and " << y << " is: "
		 // << g1.getEdge(x, y) << endl;

	// g1.addEdge("a", "c");
	// g1.addEdge("a", "c");

	cout << "Vertices: ";
    vector<string> vertVector = g1.vertices();
    vector<string>::iterator itr;
    for (auto itr : vertVector)
        cout << itr << " ";
    cout << endl;

    return 0;
}
