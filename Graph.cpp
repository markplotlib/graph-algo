// Implementation file for the Graph class
// Created by Mark Chesney, March 2020.
#include "Graph.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Graph::VertexList Graph::vertices() const {
	return vertexList;
}

void Graph::addEdge(string vFrom, string vTo, int wgt) {
    EdgeList edgeVector;
    Edge edge(vFrom, vTo, wgt);
    edgeVector.push_back(edge);

    cout << "Monday" << endl;
    // if this is a new vertex, then add to vertex list and edge list

    if (edgeList.find(vTo) == edgeList.end()) {
        edgeList.insert(pair<string, EdgeList>(vTo, edgeVector));
        vertexList.push_back(vTo);
    } else {
        // otherwise, update edge list with wgt
        edgeList.find(vTo)->second = edgeVector;
    }
}

Graph::EdgeList Graph::outgoing(Graph::Vertex vtx) const {
	return edgeList.find(vtx)->second;
}
