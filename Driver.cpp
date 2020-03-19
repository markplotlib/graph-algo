// Graphing Algorithms (Dijkstra's, Prim's)
// Data structures: Priority Queues / Heaps
#include <iostream>
#include <set>
#include <string>
#include "Heap.h"
#include "Graph.h"
using namespace std;

map<string, int> dijkstra(const Graph g, const string start) {
    unsigned long int n = g.vertices().size();     // n is |V|, number of vertices in the graph

    // initialize data structures
    map<string, string> path;
    map<string, int> shortest;
    set<string> found;

    for (auto itr : g.vertices()) {
        path.insert(pair<string, string>(itr, ""));
        shortest.insert(pair<string, int>(itr, 0));
    }
    shortest.find(start)->second = 0;

    Heap unsolved = Heap(shortest);

    // get shortest path to every other vertex
    while (found.size() < n) {

        // find closest unsolved vertex
        string closest = unsolved.dequeue().key;
        // note: distance is an unused variable.
        // int distance = unsolved.dequeue().weight;

        // closest vertex is now solved, we know that no other shorter path exists
        found.insert(closest);

        // update paths to other vertices via closest
        for (auto k : g.outgoing(closest)) {
            if (found.find(k.vTo) == found.end()) {  // key k is not found
                int new_path_to_k = shortest.find(closest)->second + k.weight;
                if (new_path_to_k < unsolved.weightMap().find(k.vTo)->second) {
                    unsolved.enqueue(k.vTo, new_path_to_k);  // fix weight in priority queue
                    shortest.find(k.vTo)->second = new_path_to_k;
                    path.find(k.vTo)->second = closest;
                }
            }
        }
    }
    return shortest;
}


int main() {

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

    // Dijkstra's Algorithm: solving single-source shortest paths problem
    dijkstra(g, "a");

    return 0;
}
