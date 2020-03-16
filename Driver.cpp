// Graphing Algorithms (Dijkstra's, Prim's)
// Data structures: Priority Queues / Heaps
#include <iostream>
#include "Heap.h"
#include "Graph.h"
using namespace std;

int main() {

    cout << "running Driver.cpp file" << endl;
    cout << "Mark: Monday noon-time" << endl;
    Graph g;
    cout << "adding edges " << "a" << "b" << "123" << endl;
    g.addEdge("a", "b", 123);

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
