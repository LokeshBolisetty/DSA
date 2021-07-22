/*
Given a string, find if there is any subsequence of length 2 or more that repeats itself 
such that the two subsequences doesn’t have the same character at the same position, 
i.e., any 0’th or 1st character in the two subsequences shouldn’t have the same index in the original string.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPalindrome(string A){
    int j = A.size()-1,i=0;
    while(i<j){
        if(A[i]!=A[j])return false;
        i++;
        j--;
    }
    return true;
}

int hasRepeatingSubsequence(string A){
    /*
    The idea is to remove all the non-repeated characters from the string and check if the resultant string is palindrome or not. 
    If the remaining string is palindrome then it is not repeated, else there is a repetition. 
    One special case we need to handle for inputs like “AAA”, which are palindrome but their repeated subsequence exists. 
    Repeated subsequence exists for a palindrome string if it is of odd length and its middle letter is same as left(or right) character.
    */
    unordered_map<char,int> p;
    int n = A.size();

    //Store the number of times each characters appears in the string
    for(int i=0;i<n;i++){
        p[A[i]]++;
    }

    //Replace all the non repeating characters with '1'
    for(int i=0;i<n;i++){
        if(p[A[i]]==1)A[i]='1';

        // If the character count is more than 2
		// we found a repetition
		//if (p[A[i]] > 2)
		//	return 1;
    }

    //To remove all the non-repeating characters
    int k=0;
    for(int i =0;i<n;i++){
        if(p[A[i]]>1){
            A[k++] = A[i];
        }
    }
    A[k]='\0';

    //Size of the string after removing the non-repeating characters
    int newSize = k;

    cout<<newSize<<endl;

    if(!isPalindrome(A.substr(0,k)))return 1;
    else{
        if(k%2==1 && A[k/2]==A[k/2-1])return 1;
        return 0;
    }
}

int main(){
    string A = "ABBA"; 
    cout<<hasRepeatingSubsequence(A)<<endl;
    return 0;
}