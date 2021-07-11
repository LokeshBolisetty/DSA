#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> SubsringConcatenation(string A, vector<string> B){
    int subSize = B[0].size();
    vector<int> ans;
    int size = A.size();
    unordered_map<string,int> m;
    for(int i =0;i<B.size();i++){
        m[B[i]]++;
    }
    int num = size-B.size()*subSize+1;
    for(int i=0;i<num;i++){
        if(m.find(A.substr(i,subSize))!=m.end()){
            int ini = i;
            unordered_map<string, int> temp=m;
            if(temp[A.substr(i,subSize)]==1)temp.erase(A.substr(i,subSize));
            else temp[A.substr(i,subSize)]--;
            i+=subSize;
            string sstring = A.substr(i,subSize);
            while(i+subSize<size && temp.find(sstring)!=temp.end()){
                if(temp.size()==0)break;
                if(temp[sstring]==1)temp.erase(sstring);
                else temp[sstring]--;
                i+=subSize;
                sstring = A.substr(i,subSize);
                
            }
            if(temp.size()==0)ans.push_back(ini);
            i = ini;
        }
    }
    return ans;
}

int main(){
    string s = "abbaccaaabcabbbccbabbccabbacabcacbbaabbbbbaaabaccaacbccabcbababbbabccabacbbcabbaacaccccbaabcabaabaaaabcaabcacabaa";
    vector<string> B = {"cac", "aaa","aba","aab","abc"};
    vector<int> ans = SubsringConcatenation(s,B);
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}