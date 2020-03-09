#include "Heap.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    Heap::Key key1 = "k1";
    Heap::Weight wgt1 = 1;

    // initialize struct KeyWeight
    // ctor 1: no-args
    Heap::KeyWeight kw1;
    kw1 = Heap::KeyWeight();
    // ctor 2: key, weight args
    Heap::KeyWeight kw1copy = Heap::KeyWeight(key1, wgt1);
    cout << "key: " << kw1copy.key << endl;
    cout << "wgt: " << kw1copy.weight << endl;

    // initialize HeapArray object
    Heap::HeapArray heapArr1;
    heapArr1.push_back(key1);
    Heap::Key key2 = "k2";
    heapArr1.push_back(key2);

    // initialize WeightMap object
    Heap::WeightMap wgtMap1;
    wgtMap1.insert( std::pair<Heap::Key, Heap::Weight>(key1, 21) );
    wgtMap1.insert( std::pair<Heap::Key, Heap::Weight>(key2, 42) );

    cout << "wgtMap1" << endl;
    cout << "size of this WeightMap object: " << wgtMap1.size() << endl;
    map<Heap::Key, int>::iterator itr;
    for (itr = wgtMap1.begin(); itr != wgtMap1.end(); itr++)
        cout << itr->first << ": " << itr->second << ". ";
    cout << endl;

    // initialize Heap object
	// ctor 1: no-args
    Heap heap1 = Heap();

    // ctor 2: build from WeightMap
    Heap heap2 = Heap(wgtMap1);

    // test empty()
    cout << "Is heap1 empty? " << boolalpha << heap1.empty() << endl;

    // for some reason, either the 1-arg ctor or empty() isn't working
    cout << "Is heap2 empty? " << boolalpha << heap2.empty() << endl;

    return 0;
}
