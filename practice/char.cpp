#include<iostream>
#include<algorithm>
#include<string.h>
#include <cstring>

using namespace std;


// A -> 65 , Z -> 90 , a -> 97 , z -> 122
// a-A=32
char* toLowerCase(char ch[]){
    for(int i=0;i<strlen(ch);i++){
        if(ch[i]>='A' && ch[i]<='Z'){
            ch[i]=ch[i]+32;
            // Other calculative step
            // ch[i]=ch[i]-'A'+'a'; 
            // dry run
            // suppose ch[i]=B
            // B-A=1 + 32 = 33
        }
    }
    return ch;
}

bool checkPalindrome(char ch[],int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j) {
        if (ch[i] != ch[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


// char ---> returns a single character
// char* ---> returns the whole array
char* reverse(char ch[]){
    int i=0;
    int j=strlen(ch)-1;
    while(i<j){
        swap(ch[i++],ch[j--]);
    }
    return ch;
}

char findMostFrequentChar(const std::string& str) {
    int freq[26] = {0}; // Assuming only lowercase a-z are of interest
    int maxFreq = 0;
    char ans = '\0';

    for (char ch : str) {
        if (std::isalpha(ch)) {
            ch = std::tolower(ch); // Convert to lowercase
            freq[ch - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i]; // Find the highest frequency
            ans = i + 'a';     // Get the corresponding character
        }
    }

    return ans;
}



int main()
{
    char ch[20];
    
    cout<<"Enter a string: ";
    cin>>ch;
    cout<<endl;

    // ch[2]='\0'; // forcefully cut the string
    // Printing the string
    cout<<"String: "<<ch<<endl;

    // Finding the length of the string

    int i=0;
    while(ch[i] != '\0'){
        i++;
    }
    cout<<"Length of string: "<<i<<endl;


    // Reversing the string
    reverse(ch);
    cout<<"Reversed string: "<<ch<<endl;


     // Converting the string to lowercase
    toLowerCase(ch);
    cout<<"Lowercase string: "<<ch<<endl;

    // Checking if the string is palindrome
    if(checkPalindrome(ch,i)){
        cout<<"The string is palindrome"<<endl;
    }
    else{
        cout<<"The string is not palindrome"<<endl;
    }

    // Finding the most frequent character
    char ans = findMostFrequentChar(ch);
    cout<<"Most frequent character: "<<ans<<endl;

    return 0;
}