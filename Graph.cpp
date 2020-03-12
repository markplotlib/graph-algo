// Implementation file for the Graph class
// Created by Mark Chesney, March 2020.
#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

Graph::Graph(const VertexList& initial) {
	vector<Vertex>::const_iterator itr;
	for (auto itr : initial) {
		vertexList.push_back(itr);
	}
}

Graph::VertexList Graph::vertices() const {
	return vertexList;
}

Graph::EdgeList Graph::outgoing(Graph::Vertex vtx) const {
	return edgeList.find(vtx)->second;
}
    
void Graph::addEdge(Graph::Vertex vFrom, Graph::Vertex vTo, int wgt) {
	bool hasOrigin = hasVertex(vFrom);
	bool hasDest = hasVertex(vTo);
	if (!hasOrigin || !hasDest)
// consider changing this to a try-catch clause
		cout << "Unable to ADD edge: Graph::Vertex not found." << endl;
	else {
		// I don't know why this fills the whole screen 
		// with some invalid pointer error.
		// adjMatrix.find(vFrom)->second.find(vTo)->second = wgt;
		cout << "adding edge..." << endl;
	}
}

bool Graph::hasVertex(Graph::Vertex vtx) {
	int end = vertexList.size();
	for (int i = 0; i < end; i++) {
		if (vertexList.at(i) == vtx)
			return true;
	}
	return false;
}