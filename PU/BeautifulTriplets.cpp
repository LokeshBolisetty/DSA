#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int BeautifulTriplets(int d,vector<int> arr){
    unordered_map<int,int> m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    if(d==0){
        int count=0;
        for(auto it=m.begin();it!=m.end();it++){
            if(m[it->first]>=3){
                int n = m[it->first];
                count+=n*(n-1)*(n-2)/6;
        }
        }
        return count;
    }
    int count=0;
    for(auto it=m.begin();it!=m.end();it++){
        if(m[it->first+d]>0 && m[it->first+2*d]>0){
            count+=it->second*m[it->first+d]*m[it->first+2*d];
        }
    }
    return count;
}
int main(){
    vector<int> arr={1,1,1,1,1,1,2,3,4,5};
    cout<<BeautifulTriplets(0,arr)<<endl;
    return 0;
}