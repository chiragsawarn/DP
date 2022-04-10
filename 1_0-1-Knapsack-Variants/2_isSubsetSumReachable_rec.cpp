// GFG-Accepted
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

bool isSubsetSum(int n, int items[], int sum){
    if(sum == 0) return true;
    if(n == 0) return false;

    if(t[n][sum] != -1) return t[n][sum];

    if(items[n-1] <= sum){
        bool included = isSubsetSum(n-1,items,sum-items[n-1]);
        bool excluded = isSubsetSum(n-1,items,sum);
        t[n][sum] = (included || excluded);
        return t[n][sum];
    }else{
        bool excluded = isSubsetSum(n-1,items,sum);
        t[n][sum] = excluded;
        return t[n][sum];
    }
}

int main(){
    int items[] = {3, 34, 4, 12, 5, 2};
    int sum = 30;
    // int sum = 9;
    int n = sizeof(items)/sizeof(int);

    memset(t,-1,sizeof(t));

    if(isSubsetSum(n,items,sum)){
        cout<<"Sum is reachable!"<<endl;
    }else{
        cout<<"Sum is NOT reachable!"<<endl;
    }
    return 0;
}