// // C++ Standard Library
// #include <algorithm>
// #include <bitset>
// #include <complex>
// #include <deque>
// #include <exception>
// #include <fstream>
// #include <functional>
// #include <iomanip>
// #include <ios>
// #include <iosfwd>
// #include <iostream>
// #include <istream>
// #include <iterator>
// #include <limits>
// #include <list>
// #include <map>
// #include <memory>
// #include <new>
// #include <numeric>
// #include <ostream>
// #include <queue>
// #include <set>
// #include <sstream>
// #include <stack>
// #include <stdexcept>
// #include <streambuf>
// #include <string>
// #include <typeinfo>
// #include <utility>
// #include <valarray>
// #include <vector>

// // C headers in C++ style
// #include <cassert>
// #include <cctype>
// #include <cerrno>
// #include <cfloat>
// #include <ciso646>
// #include <climits>
// #include <clocale>
// #include <cmath>
// #include <csetjmp>
// #include <csignal>
// #include <cstdarg>
// #include <cstddef>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <ctime>
// #include <cwchar>
// #include <cwctype>

#include<bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    struct customPair {
        int key;
        int freq;

        bool operator==(const customPair& other) const {
            return key == other.key && freq == other.freq;
        }
    };

    struct hash_pair {
        size_t operator()(const customPair& p) const {
            return hash<int>{}(p.key) ^ (hash<int>{}(p.freq) << 1);
        }
    };

    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;

        unordered_set<int> freqSet;
        for (auto [num, f] : freq) {
            if (freqSet.count(f)) return false;
            freqSet.insert(f);
        }
        return true;
    }
};



// Using hash map only -- simpler version but more memory usage

class SolutionSimple {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;

        unordered_map<int, int> freqSet;
        for (auto [num, f] : freq) {
            if (freqSet.count(f)) return false;
            freqSet[f]++;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << (sol.uniqueOccurrences(arr) ? "True" : "False") << endl;

    SolutionSimple solSimple;
    cout << (solSimple.uniqueOccurrences(arr) ? "True" : "False") << endl;

    return 0;
}