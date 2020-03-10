#include "Graph.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {    
    cout << "Graph object." << endl;
    
	Graph::Name name1 = "a";
	vector<Graph::Name> v1;	
	v1.push_back(name1);
	
	// graph of a only
    Graph g1 = Graph(v1);

	cout << "graph size: " << g1.size() << endl;
	
    return 0;
}
