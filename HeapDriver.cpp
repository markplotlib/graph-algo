#include <iostream>
#include "Heap.h"
using namespace std;

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
    // Heap::Key key3 = heapArr1.pop_back();

    // initialize WeightMap object
    Heap::WeightMap wgtMap1;
    wgtMap1.insert( std::pair<Heap::Key, Heap::Weight>(key1, wgt1) );
    wgtMap1.insert( std::pair<Heap::Key, Heap::Weight>(key2, wgt1) );

    // initialize Heap object
	// ctor 1: no-args
    Heap heap1 = Heap();

    // ctor 2: build from WeightMap
    Heap heap2 = Heap(wgtMap1);

    // empty()
    cout << boolalpha << heap1.empty() << endl;

    return 0;
}