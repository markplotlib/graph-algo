#include "Heap.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    Heap::Key ni = "nickel";
    Heap::Weight wgtNi = 28;
    Heap::Key cu = "copper";
    Heap::Weight wgtCu = 29;
    Heap::Key ag = "silver";
    Heap::Weight wgtAg = 47;
    Heap::Key au = "gold";
    Heap::Weight wgtAu = 79;
    Heap::WeightMap metalsWgtMap;
    metalsWgtMap.insert(std::pair<Heap::Key, Heap::Weight>(ni, wgtNi));
    metalsWgtMap.insert(std::pair<Heap::Key, Heap::Weight>(cu, wgtCu));
    metalsWgtMap.insert(std::pair<Heap::Key, Heap::Weight>(ag, wgtAg));
    metalsWgtMap.insert(std::pair<Heap::Key, Heap::Weight>(au, wgtAu));

    Heap metalHeap = Heap(metalsWgtMap);

    Heap::WeightMap copycat = metalHeap.weightMap();
    map<Heap::Key, int>::iterator itr = copycat.begin();
    while (itr != copycat.end()) {
        cout << itr->first << ": " << itr->second << ". ";
        itr++;
    }
    cout << endl;

    return 0;
}