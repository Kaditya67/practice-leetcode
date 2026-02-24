#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class LFUCache {
private:
    int cap;
    unordered_map<int,pair<int,int>> Cache; // Key, value, freq(To find in freq table for updating)
    unordered_map<int,list<int>> freqToKeys;    // LRU ORDER can be maintained here
    unordered_map<int,list<int>::iterator> keyToNode;    // key, Node::Iterator      ---> For better Erasing or updating using Iterator else O(N) search will be applied wothout iterator
    int minFreq;
public:
    LFUCache(int capacity) {
        this->cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(!Cache.count(key)) return -1;
        
        int val = Cache[key].first;
        int freq = Cache[key].second;
        
        freqToKeys[freq].erase(keyToNode[key]);  // Erase this key from list using this iterator
        if(freqToKeys[freq].empty()){
            freqToKeys.erase(freq); // Remove Empty frequency list
            if(minFreq==freq) minFreq++;
        }
        
        // New frequency
        freq+=1;
        freqToKeys[freq].emplace_front(key);    // New Record or insert into frequency
        keyToNode[key]=freqToKeys[freq].begin();
        // Update Key Data
        Cache[key]={val,freq};
        return val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        
        if(Cache.count(key)){
            Cache[key].first = value;
            get(key);   // Auto Update
        }else{
            if(Cache.size()==cap){
                // Remove a Key
                int rKey = freqToKeys[minFreq].back();
                freqToKeys[minFreq].pop_back();     // Take key to remove records from others
                // Kahi ye Empty toh nhi ho gya
                if(freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq); // Remove Empty frequency list
                
                keyToNode.erase(rKey);
                Cache.erase(rKey);
            }
            
            minFreq = 1;
            freqToKeys[1].emplace_front(key);
            keyToNode[key]=freqToKeys[1].begin();
            Cache[key]={value,1}; // New Entry
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LFUCache lfu(2);
    lfu.put(1, 1); // cache is {1=1}
    lfu.put(2, 2); // cache is {1=1, 2=2}
    cout << lfu.get(1) << endl; // returns 1
    lfu.put(3, 3); // evicts key 2, cache is {1=1, 3=3}
    cout << lfu.get(2) << endl; // returns -1 (not found)
    cout << lfu.get(3) << endl; // returns 3
    return 0;
}