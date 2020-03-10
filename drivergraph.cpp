#include "Graph.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {    
    cout << "Graph object." << endl;
    
	vector<string> v1;
	v1.push_back("a");
	v1.push_back("b");
	
	// graph of single-point only
    Graph g1 = Graph(v1);
	cout << "graph size: " << g1.size() << endl;

	// vector<vector<int>> adjacencyList;
	// g1.addEdge("a", "b");
	// should be (a)-->(b)
	// [0 1]
	// [0 0]

    vector<string> vertVector = g1.vertices();
    vector<string>::iterator itr;
    for (auto itr : vertVector)
        cout << itr << " ";
    cout << endl;
	
    return 0;
}
