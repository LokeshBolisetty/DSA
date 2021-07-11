#include<iostream>
#include<vector>
#include<map>
using namespace std;
void generate(string s,string digit,map<char,string> m,vector<string> &ans){
    if(digit.size()==0)ans.push_back(s);
    for(auto c:m[digit[0]]){
        s+=c;
        generate(s,digit.substr(1),m,ans);
        s.pop_back();
    }
    return;
}
vector<string> digitString(string s){
    map<char,string> m;
    m['0'] = "0";
    m['1'] = "1";
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    vector<string> ans;
    generate("",s,m,ans);
    return ans;
}
int main(){
    string digits = "23";
    vector<string> v = digitString(digits);
    for(auto x: v){
        cout<<x<<endl;
    }
    return 0;
}