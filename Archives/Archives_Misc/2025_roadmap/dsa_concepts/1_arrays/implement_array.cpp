#include<iostream>
using namespace std;

int* resizeArray(int* arr, int& size, int newSize) {
    int* newArr = new int[newSize]; // Allocate new memory
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];         // Copy old elements
    }
    delete[] arr;                   // Free old memory
    size = newSize;                 // Update size
    return newArr;                  // Return new array
}

int main(){

    // Static Array
    // int arr[5];              // Declaration of an integer array of size 5
    // int arr[5] = {1, 2, 3};  // Partial initialization (other elements are set to 0)
    // int arr[] = {1, 2, 3};   // Compiler determines the size (3 in this case)

    int arr1[5];
    for(int i=0;i<5;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<5;i++){
        cout<<arr1[i]<<" ";
    }


    // Dynamic Array
    // int* arr = new int[size]; // Allocates an array of `size` integers
    // delete[] arr;          // Deallocate memory
    int size = 5;
    int* arr2 = new int[size];
    for(int i=0;i<size;i++){
        cin>>arr2[i];
    }
    for(int i=0;i<size;i++){
        cout<<arr2[i]<<" ";
    }
    delete[] arr2;

    return 0;
}