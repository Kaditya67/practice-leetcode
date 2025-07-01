#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int cap;        // Capacity of the cache ----> Initialized only once
    list<pair<int, int>> lruList;  // Pair--> {key, value}      --> Doubly linked list from  STL
    unordered_map<int, list<pair<int, int>>::iterator> cache;      // Key --> Map(directly to NODE in the list using iterator)

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;       // If no entry found in the MAP for the key
        lruList.splice(lruList.begin(), lruList, it->second);       // splice(pos, list, it->second) --> Move the "it->second" node to the "pos" of the "lrulist" list
        return it->second->second;      // it->second is the iterator to the node in the list, and it->second->second is the value of that node
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value + move to front
            cache[key]->second = value;
            lruList.splice(lruList.begin(), lruList, cache[key]);   // Put it in the front as it was used recently
        } else {
            // Remove least recently used if full
            if (lruList.size() == cap) {
                int lruKey = lruList.back().first;  // Key of the least recently used node
                lruList.pop_back();
                cache.erase(lruKey);        // Remove from cache(MAP)
            }

        lruList.emplace_front(key, value);      // New Entry : Most recently used node
            cache[key] = lruList.begin();
        }
    }

    void display() {
        cout << "Current Cache: ";
        for (auto& [k, v] : lruList)
            cout << "[" << k << ":" << v << "] ";
        cout << "\n";
    }
};

int main() {
    LRUCache cache(3);  // capacity = 3

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);
    cache.display();  // [3:300] [2:200] [1:100]

    cache.get(2);     // Move 2 to front
    cache.display();  // [2:200] [3:300] [1:100]

    cache.put(4, 400); // Evicts key 1
    cache.display();   // [4:400] [2:200] [3:300]

    cout << "get(1): " << cache.get(1) << "\n"; // -1 (not found)

    return 0;
}



