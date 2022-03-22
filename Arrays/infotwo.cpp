/*
You are given an integer array T of size N. Also you have two integers A and B wehre (1<A<=B<=N)
Choose any two numbers C and D such that A<=D-C<=B and 1<=C<D<=N
Additionally, you need to choose C and D such that T[C]+T[D] is minimized
Find the minimum value of T[V]+T[D] for any valid value of C and D
*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //Find C and D such that A<=D-C<=B and T[C]+T[D] is minimized
    int A,B;
    cin>>A>>B;
    int C=A-1,D=B;
    int min=v[C]+v[D];
    for(int i=A-1;i<B;i++){
        for(int j=i+1;j<=B;j++){
            if(v[i]+v[j]<min){
                min=v[i]+v[j];
                C=i;
                D=j;
            }
        }
    }
    cout<<min<<endl;
    return 0;
}