#include <iostream>
using namespace std;
long long int calculate(int n,int m)
{
    n--;
    long long int nsum=0,msum=0;
    for (int i = 1; i <= m; ++i){
        msum += (m / i) * i;
        if(i<=n){
            nsum+=(n/i)*i;
        }
    }
    cout<<msum<<" "<<nsum<<endl; 
    return msum-nsum;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int L,R;
        cin>>L>>R;
        cout<<calculate(L,R)<<endl;
    }
    return 0;
}
