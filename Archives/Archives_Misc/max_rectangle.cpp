#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution {
private:
    vector<int> nextSmallerElement(int *arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        cout << "\nCalculating next smaller elements:" << endl;
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            cout << "Current element (index " << i << "): " << curr << " -> ";

            // Pop until we find a smaller element or reach the end
            while (s.top() != -1 && arr[s.top()] >= curr) {
                cout << "Pop " << arr[s.top()] << " from stack; ";
                s.pop();
            }
            
            ans[i] = s.top();
            cout << "Next smaller index for element " << curr << " is " << ans[i] << endl;

            s.push(i);
        }
        
        cout << "Next smaller element indices: ";
        for (int val : ans) cout << val << " ";
        cout << endl;

        return ans;
    }
    
    vector<int> prevSmallerElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        cout << "\nCalculating previous smaller elements:" << endl;
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            cout << "Current element (index " << i << "): " << curr << " -> ";

            // Pop until we find a smaller element or reach the start
            while (s.top() != -1 && arr[s.top()] >= curr) {
                cout << "Pop " << arr[s.top()] << " from stack; ";
                s.pop();
            }

            ans[i] = s.top();
            cout << "Previous smaller index for element " << curr << " is " << ans[i] << endl;

            s.push(i);
        }
        
        cout << "Previous smaller element indices: ";
        for (int val : ans) cout << val << " ";
        cout << endl;

        return ans; 
    }

    int largestRectangleArea(int* heights, int n) {
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = 0;

        cout << "\nCalculating largest rectangle area for current histogram row:" << endl;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = (next[i] == -1 ? n : next[i]) - prev[i] - 1;
            int newArea = height * width;
            area = max(area, newArea);

            cout << "Index " << i << " -> Height: " << height 
                 << ", Width: " << width << ", Area: " << newArea 
                 << ", Max Area So Far: " << area << endl;
        }
        
        cout << "Max area for this histogram row: " << area << endl;
        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area = largestRectangleArea(M[0], m);
        cout << "\nInitial max area from first row: " << area << endl;

        for (int i = 1; i < n; i++) {
            cout << "\nUpdating histogram for row " << i << ": " << endl;
            for (int j = 0; j < m; j++) {
                if (M[i][j] != 0) {
                    M[i][j] += M[i - 1][j];
                } else {
                    M[i][j] = 0;
                }
            }

            cout << "Updated histogram for row " << i << ": ";
            for (int j = 0; j < m; j++) cout << M[i][j] << " ";
            cout << endl;

            area = max(area, largestRectangleArea(M[i], m));
            cout << "Max area after row " << i << ": " << area << endl;
        }

        cout << "\nFinal max rectangle area in binary matrix: " << area << endl;
        return area;
    }
};

int main() {
    int T = 1;
    int n = 4, m = 4;
    int M[MAX][MAX] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    Solution obj;
    cout << "Max Rectangle Area: " << obj.maxArea(M, n, m) << endl;
}
