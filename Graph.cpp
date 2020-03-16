// Implementation file for the Graph class
// Created by Mark Chesney, March 2020.
#include "Graph.h"
#include <iostream>
<<<<<<< HEAD
#include <string>
#include <vector>
#include <map>
=======
#include <vector>
#include <string>
>>>>>>> heap-build
using namespace std;

Graph::VertexList Graph::vertices() const {
	return vertexList;
}

<<<<<<< HEAD
void Graph::addEdge(Graph::Vertex vFrom, Graph::Vertex vTo, int wgt) {
	Graph::Edge edge = Graph::Edge(vFrom, vTo, wgt);
	Graph::EdgeList edgeVector;
	edgeVector.push_back(edge);
	edgeList.insert(pair<Graph::Vertex, Graph::EdgeList>(vTo, edgeVector));
=======
void Graph::addEdge(string vFrom, string vTo, int wgt) {
    EdgeList edgeVector;
    Edge edge(vFrom, vTo, wgt);
    edgeVector.push_back(edge);

    // if this is a new vertex, then add to vertex list and edge list

    if (edgeList.find(vTo) == edgeList.end()) {
        edgeList.insert(pair<string, EdgeList>(vTo, edgeVector));
        vertexList.push_back(vTo);
    } else {
        // otherwise, update edge list with wgt
        edgeList.find(vTo)->second = edgeVector;
    }
>>>>>>> heap-build
}

Graph::EdgeList Graph::outgoing(Graph::Vertex vtx) const {
	return edgeList.find(vtx)->second;
}
