#include<iostream>
#include <vector>
using namespace std;
void generate(string s,int open,int close,vector<string> &answer){
    if(close==0){
        answer.push_back(s);
        return;
    }
    else{
        if(open>0){
            s.append("(");
            generate(s,open-1,close,answer);
            s.pop_back();
        }
        if(open<close){
            s.append(")");
            generate(s,open,close-1,answer);
            s.pop_back();
        }
    }
}
vector<string> generateParanthesis(int A){
    vector<string> v;
    generate("",A,A,v);
    return v;
}
int main(){
    int n = 3;
    vector<string> v = generateParanthesis(n);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}