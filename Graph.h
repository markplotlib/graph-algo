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
	typedef vector<string> Vertices;
	typedef map<string, int> AdjList;

    Graph() {}
    ~Graph() {}
	Graph(const Vertices& initial);

	vector<string> vertices() const;
	void addVertex(string);
	void addEdge(string vertexFrom, string vertexTo, int weight=1);

private:
	Vertices v;
	map<string, AdjList> adjMatrix;
};
