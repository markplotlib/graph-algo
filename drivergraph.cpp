#include "Graph.h"
#include <iostream>
using namespace std;

int main() {    
    cout << "Graph object." << endl;
    
    Graph g1 = Graph();

    g1.setName("bob");
	g1.setNum(143);

	cout << g1.getName() << ": " << g1.getNum() << endl;

    return 0;
}
