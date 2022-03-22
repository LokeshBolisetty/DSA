#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool checkPalindrome(string s){
    if(s.size()<=1)return true;
    unordered_map<char,int> m;
    int count = 0;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
        if(m[s[i]]&1)count++;
        else count--;
        cout<<count<<endl;
    }
    if(count<=1)return true;
    else return false;
}
int main(){
    string s = "abbae";
    cout<<boolalpha<<checkPalindrome(s)<<endl;
    return 0;
}