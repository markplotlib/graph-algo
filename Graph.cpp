// Implementation file for the Graph class
// Created by Mark Chesney, March 2020.
#include "Graph.h"
#include <iostream>
#include <string>
using namespace std;

string Graph::getName() {
	return name;
}

int Graph::getNum() {
	return num;
}

void Graph::setNum(int n) {
	num = n;
}

void Graph::setName(string n) {
	name = n;
}
