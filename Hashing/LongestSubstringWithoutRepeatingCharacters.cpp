#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int longestSubstringWithoutRepeatingCharacters(string s){
    //Sliding window gives better results
    unordered_map<char,int> m;
    int start = 1,size = 0,maxSize=0;
    for(int i=0;i<s.size();i++){
        if(m[s[i]]>start){ //>0){
            //Instead of putting -1 for all the elements that cant be included in the substring anymore, 
            //we can just check if the element in the map has value greater than start or not everytime
            //If it is less than start, its not a part of current substring. So it can be included. 
            //for(int j=start-1;j<m[s[i]]-1;j++)m[s[j]]=-1;
            maxSize= max(i-start+1,maxSize);
            start = m[s[i]]+1;
            size = 0;
        }
        else size++;
        m[s[i]] = i+1;
    }
    return max(maxSize,(int)s.size()-start+1);
}

int main(){
    string s = "aab";
    cout<<longestSubstringWithoutRepeatingCharacters(s)<<endl;
    return 0;
}