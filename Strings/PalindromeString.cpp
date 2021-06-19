#include<iostream>
using namespace std;
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
bool isPalindrome(string s){
    int n = s.size();
    int j = n-1;
    for(int i=0;i<n/2;i++,j--){
        while(i<n && !isalnum(s[i])){
            i++; //Skip all non alphanumeric characters on the left
        }
        while(j>=0 && !isalnum(s[j])){  
            j--; //Skip all non alphanumeric characters on the right
        }
        if(j>=i)if(toupper(s[i])!=toupper(s[j]))return false; //If the string doesnt satisfy palindrome condition 
        //anywhere, then return false
    }
    return true; //If no condition fails, return true
}
int main(){
    string s = "A man, a plan, a canal: Panama";
    if(isPalindrome(s))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}