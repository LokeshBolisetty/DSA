#include<iostream>
#include<vector>
#include<bitset>
#include<cmath>
using namespace std;

/*
Let G(n) represent a gray code of n bits.
Note that reverse of G(n) is also a valid sequence.
Let R(n) denote the reverse of G(n).

Note that we can construct
G(n+1) as the following :
0G(n)
1R(n)

Where 0G(n) means all elements of G(n) prefixed with 0 bit and 1R(n) means all elements of R(n) prefixed with 1.
Note that last element of G(n) and first element of R(n) is same. So the above sequence is valid.

Example G(2) to G(3) :
0 00
0 01
0 11
0 10
1 10
1 11
1 01
1 00
*/

vector<int> Editorial(int n) {
    vector<int> result(1, 0);        
    for (int i = 0; i < n; i++) {
        int curSize = result.size();
        // push back all element in result in reverse order
        for (int j = curSize - 1; j >= 0; j--) {
            result.push_back(result[j] + (1 << i));
        } 
    }
    return result;
}
vector<int> GrayCode(int A){
    long long int n = pow(2,A);
    vector<int> answer;
    for(auto x=0;x<n;x++){
        answer.push_back(x^(x>>1));
    }
    return answer;
}
int main(){
    int n = 2;
    vector<int> answer = GrayCode(n);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}