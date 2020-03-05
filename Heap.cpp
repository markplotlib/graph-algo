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
    map<Key, Weight>::const_iterator itr;
    for (auto itr = initial.begin(); itr != initial.end(); itr++) {
        // weights.insert(pair<Key, Weight>(itr->first, itr->second));
        Key key = itr->first;
        Weight weight = itr->second;
        weights.insert(pair<Key, Weight>(key, weight));
    }
}

/**
 * Check if there are more key:weight pairs in the heap.
 * @return True if no more items in the heap.
 */
bool Heap::empty() const {
    return heap.size() == 0;
}


int main() {
    Heap::Key key1 = "k1";
    Heap::Weight wgt1 = 1;

    // initialize struct KeyWeight
    // ctor 1: no-args
    Heap::KeyWeight kw1;
    kw1 = Heap::KeyWeight();
    // ctor 2: key, weight args
    Heap::KeyWeight kw2 = Heap::KeyWeight(key1, wgt1);
    cout << "key: " << kw2.key << endl;
    cout << "wgt: " << kw2.weight << endl;

    // initialize HeapArray object
    Heap::HeapArray heapArr1;
    heapArr1.push_back(key1);
    Heap::Key key2 = "k2";
    heapArr1.push_back(key2);

    // initialize WeightMap object
    Heap::WeightMap wgtMap1;
    wgtMap1.insert( std::pair<Heap::Key, Heap::Weight>(key1, wgt1) );
    wgtMap1.insert( std::pair<Heap::Key, Heap::Weight>(key2, wgt1) );

    // initialize Heap object
	// ctor 1: no-args
    Heap heap1 = Heap();

    // ctor 2: build from WeightMap
    Heap heap2 = Heap(wgtMap1);

    // test empty()
    cout << boolalpha << heap1.empty() << endl;
    cout << boolalpha << heap2.empty() << endl;

    return 0;
}