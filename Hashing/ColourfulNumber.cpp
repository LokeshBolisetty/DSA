#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
//1 12 13 2 23 3
int ColourfulNumber(int A){
    string s = to_string(A);
    vector<int> product(s.size());
    unordered_set<int> m;
    product[0]=(s[0]-'0');
    m.insert(product[0]);
    for(int i=1;i<s.size();i++){
        product[i]=product[i-1]*(s[i]-'0');
        if(m.find(product[i])!=m.end())return 0;
        m.insert(product[i]);
    }
    for(int i=0;i<product.size()-1;i++){
        for(int j=i+1;j<product.size();j++){
            if(product[i]!=0 && m.find(product[j]/product[i])!=m.end())return 0;
            else m.insert(product[j]/product[i]);
        }
    }
    return 1;
}
int main(){
    int A = 123;
    cout<<ColourfulNumber(A)<<endl;
    return 0;
}