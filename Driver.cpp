// Graphing Algorithms (Dijkstra's, Prim's)
// Data structures: Priority Queues / Heaps
#include <iostream>
#include "Heap.h"
#include "Graph.h"
using namespace std;

int main() {
    cout << "running Driver.cpp file" << endl;

    Graph g;
    g.addEdge("a", "b", 12);
    g.addEdge("a", "c", 13);
    // what follows is effectively an undirected graph representation
    g.addEdge("b", "a", 12);
    g.addEdge("c", "a", 13);

    vector<string> vertices = g.vertices();

    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        string vertex = *it;
        cout << endl << "Vertex: " << vertex << endl;

        vector<Graph::Edge> edges = g.outgoing(vertex);
        for (auto it = edges.begin(); it != edges.end(); it++)
            cout << "\t" << it->vFrom << "->" << it->vTo << " (" << it->weight << ")" << endl;

    }

    return 0;
}
