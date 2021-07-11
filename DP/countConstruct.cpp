#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int canConstruct(string s,vector<string> v,unordered_map<string,int> &m){
    if(s=="")return 1;
    int count=0;
    if(m.find(s)!=m.end())return m[s];
    for(int i=0;i<v.size();i++){
        size_t j=s.find(v[i]);
        if(j==string::npos)continue;
        else if(j==0){
            if(canConstruct(s.substr(v[i].size()),v,m)){
                m[s]++;
                count++;
            }
        }
    }
    m[s] = count;
    return count;
}
int main(){
    vector<string> v = {"e","ee","eee","eeee","eeeee","eeeeee","eeeeeee"};
    unordered_map<string, int> m;
    cout<<canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",v,m)<<endl;
    return 0;
}