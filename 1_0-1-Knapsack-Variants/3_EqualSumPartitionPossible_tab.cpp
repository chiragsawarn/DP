// GFG Accepted
// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int t[101][10001];
    Solution(){
        memset(t,-1,sizeof(t));
    }
    
    bool isSubsetSumPossible(int items[], int n, int sum){
        for(int i=0; i<=n; ++i) t[i][0] = true;
        for(int j=1; j<=sum; ++j) t[0][j] = false;
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=sum; ++j){
                if(items[i-1] <= j){
                    bool included = t[i-1][j-items[i-1]];
                    bool excluded = t[i-1][j];
                    t[i][j] = (included || excluded);
                }else{
                    bool excluded = t[i-1][j];
                    t[i][j] = excluded;
                }
            }
        }
        return t[n][sum];
    }

    int equalPartition(int N, int arr[]){
        // code here
        int total_sum = accumulate(arr,arr+N,0);
        if(total_sum&1){
            return 0;
        }else{
            int target_sum = total_sum/2;
            if(isSubsetSumPossible(arr,N,target_sum)) return 1;
            else return 0;
        }
    }
};