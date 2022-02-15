#include <iostream>
#include <vector>
#define int long long
using namespace std;
int countSwaps(vector<int> &arr, int swaps, vector<vector<int>> &roxy)
{
    int j=0;
    //int key = arr[0];
    int swap = 0;
    int pointer = 0;
    int rs = roxy.size();
    int as = arr.size();
    while(pointer<rs && roxy[pointer][0]<1)pointer++;
    for (int i = 0; i < as; i++)
    {
        //key = arr[i];
        j = i;
        if (pointer<rs && roxy[pointer][0] == i)
        {
            if (arr[roxy[pointer][1] - 1] > arr[roxy[pointer][2] - 1])
            {
                int temp = arr[roxy[pointer][1]-1];
                arr[roxy[pointer][1] - 1] = arr[roxy[pointer][2] - 1];
                arr[roxy[pointer][2] - 1] = temp;
            }
            pointer++;
        }
        while (j >= 1 && arr[j] < arr[j-1])
        {
            swap++;
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j = j-1;
        }
        //arr[j + 1] = key;
    }
    return swap;
}

signed main()
{
    int n;
    cin>> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>> a;
        v.push_back(a);
    }
    int swaps;
    cin>>swaps;
    vector<vector<int>> roxy;
    for(int i=0;i<swaps;i++){
        int a,b,c;
        cin>>a>>b>>c;
        roxy.push_back({a,b,c});
    } 
    cout << countSwaps(v, swaps, roxy) << endl;
    return 0;
}