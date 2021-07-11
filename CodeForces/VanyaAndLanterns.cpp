#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int lanterns,length;
    cin>>lanterns>>length;
    int lantern[lanterns];
    double max = INT_MIN;
    for(int i =0;i<lanterns;i++){
        int r;
        cin>>r;
        lantern[i] = r;
    }
    sort(lantern,lantern+lanterns);
    for(int i =0;i<lanterns;i++){
        if(i!=0){
        int  r = lantern[i]-lantern[i-1];
        if(r>max)max = r;
        }
    }
    max = max/2;
    if(lantern[0]!=0){
        if(lantern[0]>max)max = lantern[0];
    }
    if(lantern[lanterns-1]!=length){
        if(length-lantern[lanterns-1]>max)max = length-lantern[lanterns-1];
    }
    cout<<fixed;
    cout<<setprecision(9)<<max<<endl;
    return 0;
}
