#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    int** arr = new int*[n];
    int* colSizes = new int[n]; // Array to store the number of columns for each row

    for (int i = 0; i < n; i++) {
        int m;
        cout << "Enter the number of columns for row " << i + 1 << ": ";
        cin >> m;
        colSizes[i] = m; // Store the number of columns for this row
        arr[i] = new int[m];
        cout << "Enter elements for row " << i + 1 << ": ";
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // Print the 2D array to verify input
    cout << "The 2D array is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate the memory to avoid memory leaks
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] colSizes;

    return 0;
}
