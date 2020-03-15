#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph g;
    cout << "adding edges..." << endl;
    g.addEdge("a", "b", 12);
    g.addEdge("a", "c", 13);
    g.addEdge("b", "a", 12);  // if we want an undirected graph we have to put identical edges in both directions
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
