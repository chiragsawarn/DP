// GFG Accepted
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    bool t[2][10001];
    Solution(){
        memset(t,-1,sizeof(t));
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        t[0][0] = true;
        t[1][0] = true;
        for(int j=1; j<=sum; ++j) t[0][j] = false;
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=sum; ++j){
                if(arr[i-1] <= j){
                    bool included = t[(i+1)%2][j-arr[i - 1]];
                    bool excluded = t[(i+1)%2][j];
                    t[i%2][j] = (bool)(included || excluded);
                }else{
                    bool excluded = t[(i+1)%2][j];
                    t[i%2][j] = excluded;
                }
            }
        }
        
        return t[n%2][sum];
    }
};