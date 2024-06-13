#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());

        int result = 0;
        for (size_t i = 0; i < students.size(); ++i) {
            result += std::abs(seats[i] - students[i]);
        }
        return result;
    }
};

int main() {
    std::vector<int> seats = {4, 1, 5, 9};
    std::vector<int> students = {2, 3, 8, 6};

    Solution sol;
    int result = sol.minMovesToSeat(seats, students);
    
    std::cout << "Minimum moves to seat all students: " << result << std::endl;
    
    return 0;
}
