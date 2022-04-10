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
    
    for(int i=0; i<=n; ++i)
        t[i][0] = 1;
    for(int j=1; j<=sum; ++j)
        t[0][j] = 0;
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=sum; ++j){
            if(a[i-1] && (a[i-1] <= j)){
                int included = t[i-1][j-a[i-1]];
                int excluded = t[i-1][j];
                t[i][j] = included + excluded;
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
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
    int diff = 1;

    cout<<"No of Subsets of Given Diff : "<<findTargetSumWays(a,diff)<<endl;

    return 0;
}