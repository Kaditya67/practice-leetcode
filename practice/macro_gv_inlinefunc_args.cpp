#include <iostream>
#include <algorithm>

using namespace std;

const int num1=20;

// Function-like Macro definition
#define min(a, b) (((a) < (b)) ? (a) : (b)) 
int size=5;     // ---> global variable

// Inline function --> 1 line function  --> sometimes of 2-3 lines     
inline int max(int a, int b) { 
    return (a > b) ? a : b;             // --> replaces with the calling function
}

// default arguments
void printArray(int arr[],int end,int start=0)    // keep the default at the end
{
    for(int i=start;i<end;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{

	int a = 18;
	int b = 76;
    const int num2=30;

    cout<<"Const variable1: "<<num1<<endl;
    cout<<"Const variable2`: "<<num2<<endl;
    cout<<"Global variable: "<<size<<endl;

	cout<<"Minimum value between ";
    cout << min(a, b) << endl;

    cout<<"Maximum value between ";
    cout << max(a, b) << endl;


    int arr[5] = {1,2,3,4,5};
    int end=5;
    printArray(arr,end);
    printArray(arr,end,2);

	return 0;
}
