#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

//? Custom comparator for reverse order (descending)
struct ReverseComparator {
    bool operator()(int a, int b) const {
        std::cout << "Comparing a: " << a << " with b: " << b << std::endl;
        return a < b;  // Sort in descending order
    }
};

int main() {
    //* Creating a map with custom comparator
    std::map<int, std::string, ReverseComparator> mp;

    //? Inserting elements into the map
    mp[1] = "One";
    mp[3] = "Three";
    mp[2] = "Two";

    //* Iterating through the map using iterators
    std::cout << "Iterating through the map:" << std::endl;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    //? Accessing elements using iterators
    std::vector<int> vec = {1, 2, 2, 3, 3, 3, 4};

    // vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());  // Remove element 3
    // vec.erase(std::unique(vec.begin(), vec.end()), vec.end());      // Remove consecutive duplicates
    // int count = std::count(vec.begin(), vec.end(), 3);              // Count occurrences of 3
    // std::reverse(vec.begin(), vec.end());                              // Reverse the vector
    // auto it = std::find(vec.begin(), vec.end(), 3);                     // Find the first occurrence of 3
    
    //! Apply square function to each element
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::vector<int> result(vec.size());
    std::transform(vec2.begin(), vec2.end(), result.begin(), [](int x) { return x * x; });

    for (int x : result) {
        std::cout << x << " ";
    }

    return 0;
}
