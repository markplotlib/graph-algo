// Implementation file for the Graph class
// Created by Mark Chesney, March 2020.
#include "Graph.h"
#include <iostream>
#include <string>
using namespace std;

Graph::Graph(const Vertices& initial) {
	vector<string>::const_iterator itr;
	for (auto itr : initial) {
		v.push_back(itr);
	}
}

vector<string> Graph::vertices() const {
	return v;
}

int Graph::getEdge(string vertexFrom, string vertexTo) {
	bool hasOrigin = hasVertex(vertexFrom);
	bool hasDest = hasVertex(vertexTo);
	if (!hasOrigin || !hasDest)
// consider changing this to a try-catch clause
		return -1;
	else {
		return 555;
		// AdjList adjList = adjMatrix.find(vertexFrom)->second;
		// return adjList.find(vertexTo)->second;
		// return adjMatrix.find(vertexFrom)->second.find(vertexTo)->second;
	}
}

void Graph::addEdge(string vertexFrom, string vertexTo, int weight) {
	bool hasOrigin = hasVertex(vertexFrom);
	bool hasDest = hasVertex(vertexTo);
	if (!hasOrigin || !hasDest)
// consider changing this to a try-catch clause
		cout << "Unable to ADD edge: Vertex not found." << endl;
	else {
		// I don't know why this fills the whole screen 
		// with some invalid pointer error.
		// adjMatrix.find(vertexFrom)->second.find(vertexTo)->second = weight;
		cout << "adding edge..." << endl;
	}
}

bool Graph::hasVertex(string vertex) {
	int end = v.size();
	for (int i = 0; i < end; i++) {
		if (v.at(i) == vertex)
			return true;
	}
	return false;
}
