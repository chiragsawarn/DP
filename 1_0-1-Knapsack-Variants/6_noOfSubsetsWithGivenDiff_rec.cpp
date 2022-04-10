// Target Sum
// LeetCode Accepted
// https://leetcode.com/problems/target-sum/
#include <bits/stdc++.h>
using namespace std;

int t[21][1001];

int countOfZeros(vector<int> &a, int n){
    int count = 0;
    for(auto val:a){
        if(!val) ++count;
    }
    return count;
}

int countOfSubsetsWithGivenSum(vector<int> &a, int n, int sum){
    if(sum == 0) return 1;
    if(n == 0) return 0;
    if(t[n][sum] != -1) return t[n][sum];
    
    if(!a[n-1]) return countOfSubsetsWithGivenSum(a,n-1,sum);
    
    if(a[n-1] <= sum){
        int included = countOfSubsetsWithGivenSum(a,n-1,sum-a[n-1]);
        int excluded = countOfSubsetsWithGivenSum(a,n-1,sum);
        t[n][sum] = included + excluded;
        return t[n][sum];
    }else{
        int excluded = countOfSubsetsWithGivenSum(a,n-1,sum);
        t[n][sum] = excluded;
        return t[n][sum];
    }
}

int findTargetSumWays(vector<int>& nums, int target) {
    int count_0 = countOfZeros(nums,nums.size());
    int combinations = pow(2,count_0);
    int sumAll = accumulate(nums.begin(),nums.end(),0);
    if((sumAll + target)&1) return 0;
    int s2, s1 = abs((sumAll + target)/2);
    return (countOfSubsetsWithGivenSum(nums,nums.size(),s1)*combinations);
}

int main(){
    vector<int> a = {1,1,2,3};
    int targetSum = 1;
    memset(t,-1,sizeof(t));

    cout<<"No of Subsets of Given Diff : "<<findTargetSumWays(a,targetSum)<<endl;

    return 0;
}