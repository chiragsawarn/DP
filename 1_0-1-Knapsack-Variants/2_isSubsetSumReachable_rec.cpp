// GFG-Accepted
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int t[101][10001];
    Solution(){
        memset(t,-1,sizeof(t));
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        if(sum == 0) return true;
        if(arr.size() == 0) return false;
        if(t[arr.size()][sum] != -1) return t[arr.size()][sum];
        
        if(arr[arr.size()-1] <= sum){
            int last_val = arr[arr.size() - 1];
            arr.pop_back();
            bool included = isSubsetSum(arr,sum-last_val);
            bool excluded = isSubsetSum(arr,sum);
            t[arr.size()+1][sum] = (bool)(included || excluded);
        }else{
            arr.pop_back();
            bool excluded = isSubsetSum(arr,sum);
            t[arr.size()+1][sum] = excluded;
        }
        
        return t[arr.size()+1][sum];
    }
};