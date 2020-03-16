// Graphing Algorithms (Dijkstra's, Prim's)
// Data structures: Priority Queues / Heaps
#include <iostream>
#include "Heap.h"
#include "Graph.h"
using namespace std;

int main() {
    cout << "running Driver.cpp file" << endl;

    Graph g;
    g.addEdge("a", "d", 7);
    g.addEdge("d", "b", 2);
    g.addEdge("d", "c", 5);
    g.addEdge("b", "a", 3);
    g.addEdge("b", "c", 4);
    g.addEdge("c", "e", 6);
    g.addEdge("e", "d", 4);

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
