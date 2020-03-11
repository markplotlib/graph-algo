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

void Graph::addVertex(string vertex) {
	v.push_back(vertex);
	AdjList adjList;
	adjList.insert(pair<string, int>(vertex, 0));
	adjMatrix.insert(pair<string, AdjList>(vertex, adjList));
}

int Graph::getEdge(string vertexFrom, string vertexTo) {
	return 5;
}

bool Graph::hasVertex(string vertex) {
	int end = v.size();
	for (int i = 0; i < end; i++) {
		if (v.at(i) == vertex)
			return true;
	}
	return false;
}

void Graph::addEdge(string vertexFrom, string vertexTo, int weight) {
	bool hasOrigin = hasVertex(vertexFrom);
	bool hasDest = hasVertex(vertexTo);
	if (!hasOrigin || !hasDest)
// change this to a try-catch clause
		cout << "Unable to add edge: Vertex not found." << endl;
	else {
		cout << "able to add edge..." << endl;
	}
}
