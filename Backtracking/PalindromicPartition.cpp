#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPalindrome(string s,int i, int j){
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
void generate(string s,int st, vector<string> &row,vector<vector<string>> &res){
    if(st==s.length()){
        res.push_back(row);
        return;
    }
    for(int i=st;i<s.size();i++){
        if(isPalindrome(s,st,i)){
            row.push_back(s.substr(st,i-st+1));
            generate(s,i+1,row,res);
            row.pop_back();
        }
    }
    return;
}
vector<vector<string>> PalindromePartition(string s){
    vector<vector<string>> res;
    vector<string> row;
    generate(s,0,row,res);
    return res;
}
int main(){
    string s = "nitin";
    vector<vector<string>> ans = PalindromePartition(s);
    for(auto v:ans){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}