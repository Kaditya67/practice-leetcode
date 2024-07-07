#include<iostream>

using namespace std;

class Solution {
private:
    void bottleCount(int drinkableBottles, int numExchange, int &nonDrinkable, int &result){
        if(drinkableBottles == 0 && nonDrinkable < numExchange){
            return;
        }

        result += drinkableBottles;
        nonDrinkable += drinkableBottles;

        if(nonDrinkable >= numExchange){
            int newDrinkable = nonDrinkable / numExchange;
            nonDrinkable = nonDrinkable % numExchange;
            bottleCount(newDrinkable, numExchange, nonDrinkable, result);
        }
    }
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int nonDrinkable = 0;
        int result = 0;
        bottleCount(numBottles, numExchange, nonDrinkable, result);
        return result;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Solution s;
    cout << s.numWaterBottles(n, m);
    return 0;
}
