#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> LPS(string A){
    int n = A.size();
    vector<int> prix(n,0);
    for(int i=1;i<n;i++){
        int j = prix[i-1];
        while(j>0 && A[i]!=A[j]){
            j = prix[j-1];
        }
        if(A[i]==A[j])j++;
        prix[i] = j;
    }
    return prix;
}
int AppendsForPalindrome(string A){
    string s = A;
    reverse(A.begin(),A.end());
    s = A+'#'+s;
    vector<int> v = LPS(s);
    return A.size()-v[s.size()-1];
}
int MinimumAppendsforPalindromes(string A){
    int n=A.size(),i =0,j=n-1;
    int temp=1;
    while(i<j){
        if(A[i]!=A[j] && j==A.size()-1){
            i++; //If the letters don't match, go right upto until they match like for the case of abb
        }
        temp=i+1;
        while(i<j && A[i]==A[j]){
            i++;
            j--;//If they form a palindrome, keep going and check if the whole substring from i to j is a string
        }
        if(A[i]!=A[j] && j!=n-1){
            i=temp;
            j=A.size()-1;//If some letter doesnt match in between, the whole string upto now is not a palindrome. So shift j to the end
            //Like for the example of "aannba", we see A[0] == A[end] and think that its a palindrome
            //Later when we see A[1]!=A[end-1] the whole string is not a palindrome. So shift j to end and search for a smaller palindrome
        }
    }
    return temp-1;
}
int main(){
    string A = "eeefeee";
    cout<<AppendsForPalindrome(A)<<endl;
    return 0;
}