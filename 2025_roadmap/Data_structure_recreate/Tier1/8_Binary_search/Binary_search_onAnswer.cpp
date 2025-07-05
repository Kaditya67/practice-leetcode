#include <bits/stdc++.h>
using namespace std;

// ✅ Helper function to check if Koko can eat all bananas at speed k within h hours
bool canEat(vector<int>& piles, int k, int h) {
    int time = 0;
    for (int pile : piles)
        time += (pile + k - 1) / k; // Same as ceil(pile / k) --> one extra to bring 5/2 = 2 but we want 3 that is ceil so we do 6/2 to get 3.
    return time <= h;
}

// ✅ Binary search to find the minimum possible eating speed
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;        // Try eating 1 at a time
    int high = *max_element(piles.begin(), piles.end());        // He can eat maximum this much at a time

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canEat(piles, mid, h))  // If he eats all then look for smaller
            high = mid;  // Try smaller speed
        else
            low = mid + 1; // Need more speed
    }

    return low;
}

int main() {
    vector<int> bananaPiles = {3, 6, 7, 11};
    int h = 8;

    int minSpeed = minEatingSpeed(bananaPiles, h);
    cout << "Minimum eating speed: " << minSpeed << " bananas/hour" << endl;

    return 0;
}
