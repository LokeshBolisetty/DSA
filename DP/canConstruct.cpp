#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool canConstruct(string s,vector<string> v,unordered_map<string,bool> &m){
    if(s=="")return true;
    if(m.find(s)!=m.end())return m.find(s)->second;
    for(int i=0;i<v.size();i++){
        size_t j=s.find(v[i]);
        if(j==string::npos)continue;
        else if(j==0){
            if(canConstruct(s.substr(v[i].size()),v,m))
                m[s] = true;
                return true;
        }
    }
    m[s]=false;
    return false;
}
int main(){
    vector<string> v = {"bo","rd","ate","t","ska","sk","boar"};
    unordered_map<string, bool> m;
    cout<<canConstruct("skateboard",v,m)<<endl;
    return 0;
}