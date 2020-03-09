/**
 * heap.h
 * Heap class -- implements a min heap with ability to change a weight already in the heap.
 *
 * Entries in the heap are keyed by a unique string so the weight can subsequently be changed
 * and so when the min weight is dequeued it can also be identified by its key for use by the client.
 *
 * Min heap. Elements are key:weight pairs. Operations are:
    1. construct from set of key:weight pairs, Θ(n)
    2. enqueue a new or existing key with its current weight, Θ(log n)
    3. dequeue the key with the minimum weight, Θ(log n)
    4. empty tells if the heap is empty, Θ(1)
 *
 * @author Kevin Lundeen, Seattle University
 * @see CPSC5031, Winter 2018, HW #8
 */

#pragma once
#include <string>
#include <vector>
#include <map>

class Heap {
public:
    typedef int Weight;
    typedef std::string Key;
    typedef std::vector<Key> HeapArray;
    typedef std::map<Key, Weight> WeightMap;

    /**
     * Data structure used to return a key:weight pair.
     */
    struct KeyWeight {
        Key key;
        Weight weight;
        KeyWeight() : key(""), weight(0) {}
        KeyWeight(Key k, Weight w) : key(k), weight(w) {}
    };

    Heap() {}
    ~Heap() {}

    /**
     * Construct a heap from the given initial list, Θ(n) time.
     * @param initial start with these keys and their weights
     */
    Heap(const WeightMap& initial);

    /**
     * Check if there are more key:weight pairs in the heap.
     * @return True if no more items in the heap.
     */
    bool empty() const;

    /**
     * Put key into heap with given weight. If key is already present, this will change the weight and repair
     * the heap as necessary.
     * @param key    key which is to be added or modified
     * @param weight desired weight for given key
     */
    void enqueue(Key key, int weight);

    /**
     * Remove minimum element and return its key and weight.
     * @return the key:weight of the minimum weight in the heap.
     */
    KeyWeight dequeue();

    /**
     * Get a list of all the key:weight pairs currently in the heap.
     * @return list of key:weight pairs (arbitrary order)
     */
// const WeightMap& weightMap() const;

private:
    typedef std::map<Key, int> PlaceMap;

    HeapArray heap;
    WeightMap weights;
    PlaceMap place;

    int last() const;
    int parent(int i) const;
    int leftChild(int p) const;
    int rightChild(int p) const;
    Weight weight(int i) const;
    void swapUp(int i);
    void swapDown(int p);
    void heapConstruct();
};
