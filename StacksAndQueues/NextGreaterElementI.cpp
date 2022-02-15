/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1,vector<int> &nums2){
    //We will make a map which stores the next greater element for all the elements in nums2. 
    //This proces will take O(nums2.size()) time and we can retrieve the results in O(1) time using the map.

    //Holds {element,nextGreaterElement} pairs of n2
    unordered_map<int,int> m;
    //Holds elements
    stack<int> s;
    for(int i=0;i<nums2.size();i++){
        while(!s.empty() && nums2[i]>s.top()){
            m.insert({s.top(),nums2[i]});
            s.pop();
        }
        s.push(nums2[i]);
    }
    while(!s.empty()){
        m.insert({s.top(),-1});
        s.pop();
    }
    vector<int> ans;
    for(int i=0;i<nums1.size();i++){
        ans.push_back(m[nums1[i]]);
    }
    return ans;
}
int main(){
    vector<int> nums1 = {1,3,5,2,4};
    vector<int> nums2 = {5,4,3,2,1};
    vector<int> ans = nextGreaterElement(nums1,nums2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}