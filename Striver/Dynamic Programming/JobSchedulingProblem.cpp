#include<iostream>
#include<vector>

using namespace std;

#include<algorithm>
bool compareJobs(const vector<int> &v1, const vector<int> &v2){
    if(v1[1]!=v2[1])return v2[1]<v1[1]; // Sorting in descending order of deadlines
    return v2[0]<v1[0]; //sorting in decreasing order of profits
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int numOfJobs = jobs.size();
    sort(jobs.begin(), jobs.end() , compareJobs);
    vector<bool> slotAvailable(numOfJobs+1,true);
    slotAvailable[0] = false;
    int deadline = jobs[0][0], answer = 0;
    for(int i=0;i<numOfJobs && deadline>0;i++){
        for(int j=min(jobs[i][0], numOfJobs);j>=0;j--){
            if(slotAvailable[j]){
                slotAvailable[j] = false;
                answer += jobs[i][1];
                break;
            }
        }
    }
    return answer;
}


int main(){
    //first value is the deadline. Each job takes exaclty one unit of time
    //Second value is the profit
    vector<vector<int>> jobs = {{2,30},
                                {2,40},
                                {1,10},
                                {1,10}};
    cout<<jobScheduling(jobs)<<endl;
    return 0;
}