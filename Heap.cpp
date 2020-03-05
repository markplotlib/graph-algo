// Implementation file for the enhanced heap class
// Created by Mark Chesney, March 2020.
#include "Heap.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Constructor 1: no-args
// Heap::Heap() {
//     Heap::Key keyA = "keyA";
//     heap.push_back(keyA);
// }

/**
 * Construct a heap from the given initial list, Θ(n) time.
 * @param initial start with these keys and their weights
 */
Heap::Heap(const WeightMap& initial) {
    weights = initial;
}

/**
 * Check if there are more key:weight pairs in the heap.
 * @return True if no more items in the heap.
 */
bool Heap::empty() const {
    return heap.size() == 0;
}
