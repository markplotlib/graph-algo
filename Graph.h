/**
 * Graph.h
 * Graph class -- builds graphs as adjacency lists,
 *  with vertices labeled by a string name,
 *  and directed, weighted edges (default weight of 1)
 * 
 * @author Mark Chesney, Seattle University
 * @see CPSC5031, Winter 2020, HW #8
 */
#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;

class Graph {
public:
    typedef string Vertex;
    struct Edge {
        Vertex vFrom, vTo;
        int weight;
        Edge(Vertex vFrom, Vertex vTo, int weight) : vFrom(vFrom), vTo(vTo), weight(weight) {}
    };
    typedef vector<Vertex> VertexList;
    typedef vector<Edge> EdgeList;

	Graph() {};
	Graph(const VertexList& initial);

    void addEdge(Vertex vFrom, Vertex vTo, int weight=1);
    EdgeList outgoing(Vertex vtx) const;
    VertexList vertices() const;
	
private:
    VertexList vertexList;
    map<Vertex, EdgeList> edgeList;
};
