#include<iostream>
#include <vector>
using namespace std;
vector<int> SieveOfEratosthenes(int A){
    vector<bool> b(A+1,true);
    for(int i=2;i*i<=A;i++){
        for(int j=i*i;j<=A;j=j+i){
            b[j]=false;
        }
    }
    vector<int> prime;
    for(int i=2;i<=A;i++){

        if(b[i])prime.push_back(i);
    }
    return prime;
}
int main(){
    int n=100;
    vector<int> primes = SieveOfEratosthenes(n);
    for(int i=0;i<primes.size();i++){
        cout<<primes[i]<<" ";
    }
    return 0;
}