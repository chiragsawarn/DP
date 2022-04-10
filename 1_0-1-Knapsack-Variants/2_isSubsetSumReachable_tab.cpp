// GFG Accepted
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    bool t[101][10001];
    Solution(){
        memset(t,-1,sizeof(t));
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        for(int i=0; i<=n; ++i) t[i][0] = true;
        for(int j=1; j<=sum; ++j) t[0][j] = false;
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=sum; ++j){
                if(arr[i-1] <= j){
                    bool included = t[i-1][j-arr[i - 1]];
                    bool excluded = t[i-1][j];
                    t[i][j] = (bool)(included || excluded);
                }else{
                    bool excluded = t[i-1][j];
                    t[i][j] = excluded;
                }
            }
        }
        
        return t[n][sum];
    }
};