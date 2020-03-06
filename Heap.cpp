// Implementation file for the enhanced heap class
// Created by Mark Chesney, March 2020.
#include "Heap.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Construct a heap from the given initial list, Θ(n) time.
 * @param initial start with these keys and their weights
 */
Heap::Heap(const WeightMap& initial) {
    if (initial.size() == 0) {
        Heap();
    } else {   
        map<Key, Weight>::const_iterator itr;
        for (auto itr : initial) {
            Key key = itr.first;
            Weight weight = itr.second;
            weights.insert(pair<Key, Weight>(key, weight));

            enqueue(key, weight);
        }
    }
}

/**
 * Check if there are more key:weight pairs in the heap.
 * @return True if no more items in the heap.
 */
bool Heap::empty() const {
    return heap.size() == 0;
}

/**
 * Put key into heap with given weight. If key is already present, this will change the weight and repair
 * the heap as necessary.
 * @param key    key which is to be added or modified
 * @param weight desired weight for given key
 */
void Heap::enqueue(Key key, int weight) {

    // int old_weight;

    if (weights.find(key) == weights.end()) {
        // key not found in weights -- insert new key
        weights.insert(pair<Key, Weight>(key, weight));
    } else {
        // found it
        // old_weight = weights.at(key);
    }

    // heap.insert(pair<Key, Weight>(key, weight));
}
