#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<vector<string>> allConstruct(string s, vector<string> v,unordered_map<string,vector<vector<string>>> &m){
    vector<vector<string>> ans={};
    if(s=="")return {{}};
    if(m.find(s)!=m.end())return m[s];
    for(int i=0;i<v.size();i++){
        size_t j = s.find(v[i]);
        if(j==0){
            vector<vector<string>> suffixWays = allConstruct(s.substr(v[i].size()),v,m); 
            if(suffixWays.size()!=0)
            for(int t=0;t<suffixWays.size();t++){
                suffixWays[t].insert(suffixWays[t].begin(),v[i]);//actually has to be appended in the starting
                ans.push_back(suffixWays[t]);
            }
            // else{
            //     ans.push_back({v[i]});
            // }
        }
    }
    return ans;
}
int main(){
    vector<string> v={"a","aa","aaa","aaaa","aaaaa","aaaaaa"};
    //vector<string> v = {"bo","rd","ate","t","ska","sk","boar"};
    unordered_map<string, vector<vector<string>>> p={};
    vector<vector<string>> answer = allConstruct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaz",v,p);
    for(int i =0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}