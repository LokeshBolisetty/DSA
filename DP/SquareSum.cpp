//Find the number of ways of forming a given number with perfect squares only
//Asked in flipkart
#include<iostream>
#include<vector>
using namespace std;
int countWays(int N)
{   
    #define MOD 1000000007
    vector<long long> A;
    long long j = 1;
    
	vector<long long> count(N + 1,0);
	count[0] = 1;
    while(j*j<=N && j<=50){
        A.push_back(j*j);
        j++;
        count[j*j]=1;
    }
    int m = A.size();

	for (int i = 1; i <= N; i++){
		for (int j = 0; j < m; j++){
			if (i >= A[j] ){
				count[i] ++;
                count[i]%=MOD;
            }//else break;
        }
    }
	return count[N];
	
}
int main(){
    int N = 17;
    cout<<countWays(N)<<endl;
}

// #include<iostream>
// #include<vector>
// using namespace std;
// int bestSum(int n){
//     int N = n;
//     #define MOD 1000000007
//     vector<long long> A;
//     int count=0;
//     long long j = 1;
//     while(j*j<=N && j<=50){
//         A.push_back(j*j);
//         j++;
//     }
//     int m = A.size();

//     vector<int> best;
//     vector<vector<int>> v(n+1,vector<int>(1,-1));
//     for(int i=0;i<A.size();i++){
//         vector<int> x;
//         x.push_back(A[i]);
//         if(A[i]<n+1)v[A[i]]=x;
//     }
//     v[0]={1};
//     //bool flag = false;
//     for(int i=1;i<n+1;i++){
//         if(v[i][0]>0){
//             for(int j=0;j<A.size();j++){
//                 int x = i+A[j];
//                 if(x>=n+1)continue;
//                 v[x]=v[i];
//                 v[x].push_back(A[j]);
//                 //if(x==n)flag = true;
//             }
//         }
//         if(v[n][0]>0){
//             if(best.size()==0 ||best.size()>v[n].size())best = v[n];
//             //if(flag){
//                 count++;
//             //     flag = false;
//             // }
//         }
//     }
//     return count;
// }
// int main(){
//     // vector<int> v = bestSum(4);
//     // for(int x:v)cout<<x<<" ";
//     // cout<<endl;
//     cout<<bestSum(4)<<endl;
//     return 0;
// }