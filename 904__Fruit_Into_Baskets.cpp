#include<bits/stdc++.h>
using namespace std;

class Solution {    // Slow with sliding window and unordered_map
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> buckets;

        int left=0, maxFruits=0;
        for(int right=0;right<fruits.size();++right){
            buckets[fruits[right]]++;

            while(buckets.size()>2){
                buckets[fruits[left]]--;
                if(buckets[fruits[left]]==0){
                    buckets.erase(fruits[left]);
                }
                left++;
            }

            maxFruits = max(maxFruits, right-left+1);
        }
        return maxFruits;
    }
};

class Solution2 {    // Optimized with two pointers and tracking last two fruits
public:
    int totalFruit(vector<int>& fruits) {
        int lastFruit = -1, secondLastFruit = -1;
        int lastFruitCnt = 0;
        int currMax = 0, maxFruitCount = 0;

        for (int fruit : fruits) {
            if (fruit == lastFruit || fruit == secondLastFruit) {
                currMax += 1;
            } else {
                currMax = lastFruitCnt + 1;
            }

            if (fruit == lastFruit) {
                lastFruitCnt += 1;
            } else {
                lastFruitCnt = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }

            maxFruitCount = max(maxFruitCount, currMax);
        }

        return maxFruitCount;
    }
};


int main() {
    Solution s;
    vector<int> fruits = {1,2,1};
    cout << s.totalFruit(fruits) << endl;
    return 0;
}
