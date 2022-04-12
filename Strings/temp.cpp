#include<iostream>
using namespace std;
    bool isPalindrome(string s){
        int i = 0;
        int n = s.size();
        while(i<n-i-1){
            if(s[i]!=s[n-i-1])return false;
            i++;
        }
        cout<<"returning true for "<<s<<endl;
        return true;
    }
    bool validPalindrome(string s) {
        if(isPalindrome(s))return true;
        int i = 0,n=s.size();
        while(i<n-1-i){
            if(s[i] != s[n-i-1]){
                //Either remove s[i] or s[n-i]
                string temp1 = s;
                temp1.erase(i,1);
                cout<<"temp1 is "<<temp1<<endl;
                if(isPalindrome(temp1))return true;
                string temp2 = s;
                temp2.erase(n-i-1,1);
                cout<<"temp2 is "<<temp2<<endl;
                if(isPalindrome(temp2))return true;
                return false;
            }
            i++;
        }
        return false;
    }
int main(){
    string s =  "edaeadeasbccbaedaeadep";
    cout<<validPalindrome(s)<<endl;
    return 0;
}