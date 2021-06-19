#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> LPS(string A){
    int n = A.size();
    vector<int> prix(n,0);
    for(int i=1;i<n;i++){
        int j = prix[i-1];
        while(j>0 && A[i]!=A[j]){
            j = prix[j-1];
        }
        if(A[i]==A[j])j++;
        prix[i] = j;
    }
    return prix;
}
int MinCharToMakePalindrome(string A){
    string s = A;
    reverse(A.begin(),A.end());
    s += '#'+A;
    vector<int> v = LPS(s);
    return A.size()-v[s.size()-1];
}   
int main(){
    string A = "aa";
    cout<<MinCharToMakePalindrome(A)<<endl;
    return 0;
}