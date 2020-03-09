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
        }
        heapConstruct();
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
    int old_w;
    int i;
    map<Key, Weight>::iterator itr = weights.find(key);
    if (itr != weights.end()) {
        // key found -- update it
        old_w = weights.find(itr->first)->second;
        i = place.find(itr->first)->second;
    } else {
        // key not found in weights -- insert new key
        heap.push_back(key);                    // Py:  self.heap.append(key)
        old_w = 0;                              // Py:  old_w = None
        i = last();                             // Py:  i = self._last()
        place.insert(pair<Key, int>(key, i));   // Py:  self.place[key] = i
    }
    weights.find(itr->first)->second = weight;     // Py: self.weights[key] = weight
    if (old_w == 0 || old_w > weight)
        swapUp(i);
    else if (old_w < weight)
        swapDown(i);
}

/**
 * Remove minimum element and return its key and weight.
 * @return the key:weight of the minimum weight in the heap.
 */
Heap::KeyWeight Heap::dequeue() {
    if (last() < 0)
        return Heap::KeyWeight();

    // retrieve the minimum element (at the root)
    Key key = heap.at(0);
    Weight weight = weights.find(key)->second;
    weights.erase(key);
    place.erase(key);

    // remove the last element and place it at the root, then fix the heap
    if (last() > 0) {
        heap.at(0) = heap.at(last());
        heap.pop_back();
        place.find(heap.at(0))->second = 0;
        swapDown(0);
    } else {
        heap.pop_back();
    }

    return KeyWeight(key, weight);
}

/**
 * Get a list of all the key:weight pairs currently in the heap.
 * @return list of key:weight pairs (arbitrary order)
 */
// const WeightMap& weightMap() const {
//     return weights;
// }

int Heap::last() const {
    return heap.size() - 1;
}

int Heap::parent(int i) const {
    return (i - 1) >> 1;    // bit-wise for (i-1) // 2
}

int Heap::leftChild(int p) const {
    return (p << 1) + 1;  // bit-wise for 2*p + 1
}

int Heap::rightChild(int p) const {
    return leftChild(p) + 1;
}

Heap::Weight Heap::weight(int i) const {
    if (i > last())
        return 0;
    else
        return weights.find(heap.at(i))->second;
}

void Heap::swapUp(int i) {
    while (i > 0) {
        int p = parent(i);
        if (weight(i) < weight(p)) {
            Key tmp = heap.at(i);
            heap.at(i) = heap.at(p);        // Python: self.heap[i] = self.heap[p]
            heap.at(p) = tmp;               // Python: self.heap[p] = self.heap[i]
            place.find(heap.at(i))->second = i;
            place.find(heap.at(p))->second = p;            
            i = p;
        } else
            i = -1;  // exit while-loop
    }
}

void Heap::swapDown(int p) {
    int child = leftChild(p);
    int right = rightChild(p);
    int childWgt = weight(child);
    if (childWgt != 0) {
        int rightWgt = weight(right);
        if ((rightWgt != 0) && (rightWgt < childWgt)) {
            child = right;
            childWgt = rightWgt;
        }
        if (weight(p) > childWgt) {
            Key tmp = heap.at(child);
            heap.at(child) = heap.at(p);
            Key placeKeyChild = heap.at(child);
            place.find(placeKeyChild)->second = child;
            Key placeKeyParent = heap.at(p);
            place.find(placeKeyParent)->second = p;
        }
    }
}

void Heap::heapConstruct() {
    int lastParent = parent(last());
    for (int i = lastParent; i >= 0; i--)
        swapDown(i);
}
