#include<iostream>
#include<vector>
using namespace std;

int min(int a, int b, int c){
    int minab = min(a, b);
    return min(c, minab);
}
int max(int a, int b, int c){
    int maxab = max(a, b);
    return max(maxab, c);
}
int maximumProduct(vector<int> &arr, int n)
{
	int peh=arr[0], answer=arr[0],speh=arr[0];
    for(int i=1;i<arr.size();i++){
        int temp = min(arr[i], speh*arr[i],peh*arr[i]);
        peh = max(arr[i], peh*arr[i], speh*arr[i]);
        speh = temp;
        answer = max(answer, peh);
        //cout<<speh<<"\t"<<peh<<"\t"<<answer<<endl;
    }
    return answer;
}

int main(){
    vector<int> v = {6,0,2,-4};
    cout<<maximumProduct(v, v.size())<<endl;
    return 0;
}