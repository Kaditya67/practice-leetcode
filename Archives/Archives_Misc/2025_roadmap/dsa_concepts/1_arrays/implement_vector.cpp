#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    //* Concepts
    // std::vector<int> vec;                // Empty vector of integers
    // std::vector<int> vec(5);             // Vector of size 5, initialized with default values (0 for int)
    // std::vector<int> vec(5, 10);         // Vector of size 5, initialized with value 10
    // std::vector<int> vec = {1, 2, 3};    // Initialization using initializer list

    vector<int> vec;       // Dynamic array using STL
    //? Adding elements
    vec.push_back(1);

    //? Accessing elements
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout<<endl;

    //? Resizing
    vec.resize(10);        // Changes size to 10
    vec[5] = 100;          // Assigning value to new index

    //? Printing resized array
    for (int &i : vec) {
        cout << i << " ";
    }
    cout<<endl;

    //* Methods
    // vec.at(11) = 200;      // at() - throws an exception if index is out of bounds
    // vec.pop_back();      // Removes the last element
    // vec.insert(vec.begin() + 1, 10); // Inserts 10 at index 1
    // vec.erase(vec.begin() + 1);     // Removes the second element
    // vec.erase(vec.begin(), vec.begin() + 2); // Removes first two elements
    // vec.clear();         // Empties the vector


    //* Iterators
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    cout<<endl;

    //* Important Methods
    std::cout << vec.size()<<endl;    // Returns the number of elements
    std::cout << vec.capacity()<<endl;    // Returns the allocated space
    std::cout << vec.empty()<<endl;    // Returns true if the vector is empty

    // vec.resize(10);      // Resizes to hold 10 elements
    // vec.reserve(50);     // Reserves space for at least 50 elements
    // vec.shrink_to_fit();    // Shrinks the capacity to fit the size

    //* Advanced Methods
    std::sort(vec.begin(), vec.end()); // Sorts in ascending order
    std::sort(vec.rbegin(), vec.rend()); // Sorts in descending order

    auto it = std::find(vec.begin(), vec.end(), 10); // Finds 10
    if (it != vec.end()) {
        std::cout << "Found: " << *it;
    }

    //* Custom Comparators
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b; // Sorts in descending order
    });



    //! 2D Vector
    std::vector<std::vector<int>> matrix(3, std::vector<int>(4, 0));    // 3 rows, 4 columns, initialized with 0

    // Access and modify elements
    matrix[1][2] = 5;

    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }


    //! 3D Vector
    std::vector<std::vector<std::vector<int>>> cube(2, std::vector<std::vector<int>>(3, std::vector<int>(4, 0)));    // 2 layers, 3 rows, 4 columns, initialized with 0


    return 0;
}
