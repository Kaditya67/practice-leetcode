/**
 * Problem: LeetCode 146 - LRU Cache
 * ATOMIC TOPIC: std::list + std::unordered_map
 */

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache {
public:
  list<pair<int, int>> ll;
  unordered_map<int, list<pair<int, int>>::iterator> mp;
  int maxSize;

  LRUCache(int capacity) { maxSize = capacity; }

  int get(int key) {
    if (mp.find(key) == mp.end())
      return -1;

    int value = mp[key]->second; // save value
    // Optimization: ll.splice(ll.begin(), ll, mp[key]) is faster than
    // erase/push
    ll.erase(mp[key]);
    ll.push_front({key, value}); // push in ll
    mp[key] = ll.begin();        // store iterator in mp
    return value;
  }

  void put(int key, int value) {
    if (mp.find(key) != mp.end()) { // if found
      ll.erase(mp[key]);            // remove old node
    } else if (ll.size() == maxSize) {
      int lruKey = ll.back().first;
      ll.pop_back();
      mp.erase(lruKey);
    }
    ll.push_front({key, value});
    mp[key] = ll.begin();
  }
};

int main() {
  LRUCache *lRUCache = new LRUCache(2);
  lRUCache->put(1, 1); // cache is {1=1}
  lRUCache->put(2, 2); // cache is {1=1, 2=2}
  cout << "get(1): " << lRUCache->get(1) << " (Expected: 1)"
       << endl;        // return 1
  lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  cout << "get(2): " << lRUCache->get(2) << " (Expected: -1)"
       << endl;        // returns -1 (not found)
  lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  cout << "get(1): " << lRUCache->get(1) << " (Expected: -1)"
       << endl; // return -1 (not found)
  cout << "get(3): " << lRUCache->get(3) << " (Expected: 3)"
       << endl; // return 3
  cout << "get(4): " << lRUCache->get(4) << " (Expected: 4)"
       << endl; // return 4

  delete lRUCache;
  return 0;
}
