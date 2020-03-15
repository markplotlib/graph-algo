// Implementation file for the Graph class
// Created by Mark Chesney, March 2020.
#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

Graph::VertexList Graph::vertices() const {
	return vertexList;
}

void Graph::addEdge(Graph::Vertex vFrom, Graph::Vertex vTo, int wgt) {
	Graph::Edge edge = Graph::Edge(vFrom, vTo, wgt);
	Graph::EdgeList edgeVector;
	edgeVector.push_back(edge);
	edgeList.insert(pair<Graph::Vertex, Graph::EdgeList>(vTo, edgeVector));
}

Graph::EdgeList Graph::outgoing(Graph::Vertex vtx) const {
	return edgeList.find(vtx)->second;
}
