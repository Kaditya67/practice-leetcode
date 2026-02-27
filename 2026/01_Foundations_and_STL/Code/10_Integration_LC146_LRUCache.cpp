/**
 * PROBLEM: LeetCode 146 - LRU Cache
 * ORDER: 10
 * ATOMIC TOPIC: Final STL Integration (Maps + Lists)
 * 
 * DESCRIPTION:
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * 
 * CONSTRAINTS:
 * - 1 <= capacity <= 3000
 * - get and put must each run in O(1) average time complexity.
 */

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        // TODO: Initialize cache
    }
    
    int get(int key) {
        // TODO: O(1) retrieval
        return -1;
    }
    
    void put(int key, int value) {
        // TODO: O(1) insertion and eviction
    }
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    cout << "Get 1: " << lRUCache.get(1) << " (Expected: 1)" << endl;
    lRUCache.put(3, 3); // evicts key 2
    cout << "Get 2: " << lRUCache.get(2) << " (Expected: -1)" << endl;

    return 0;
}
