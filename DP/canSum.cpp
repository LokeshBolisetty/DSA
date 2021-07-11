#include<iostream>
#include<vector>
using namespace std;
bool canSum(int n,vector<int> num){
    vector<bool> b(n+1,false);
    b[0]=1;
    for(int i=0;i<n+1;i++){
        if(b[i])
        for(int j=0;j<num.size();j++){
            if(i+num[j]<n+1)b[i+num[j]]=1;
        }
    }
    return b[n];
}
int main(){
    cout<<canSum(10,{3,4,7,9,10});
    cout<<canSum(7,{2,3});
    cout<<canSum(7,{5,4,3,7});
    cout<<canSum(7,{2,4});
    cout<<canSum(8,{2,3,5});
    cout<<canSum(300,{7,14});

    return 0;
}