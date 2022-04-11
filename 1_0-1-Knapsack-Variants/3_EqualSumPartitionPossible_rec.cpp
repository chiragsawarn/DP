// GFG Accepted
// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int t[101][1001];
    Solution(){
        memset(t,-1,sizeof(t));
    }
    
    bool isSubsetSumPossible(int items[], int n, int sum){
        if(sum == 0) return true;
        if(n == 0) return false;
        if(t[n][sum] != -1) return t[n][sum];
    
        if(items[n-1] <= sum){
            bool included = isSubsetSumPossible(items,n-1,sum-items[n-1]);
            bool excluded = isSubsetSumPossible(items,n-1,sum);
            t[n][sum] = (included || excluded);
            return t[n][sum];
        }else{
            bool excluded = isSubsetSumPossible(items,n-1,sum);
            t[n][sum] = excluded;
            return t[n][sum];
        }
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