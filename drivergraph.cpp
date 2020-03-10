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
	
    return 0;
}
