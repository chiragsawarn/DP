// GFG Accepted
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int n, int items[], int sum){
    bool t[n+1][sum+1];
    // initialization
    // 1. sum = 0  is always attainable
    for(int i=0; i<=n; ++i) t[i][0] = true;
    // 2. No sum is attainable when no items are available 
    for(int j=1; j<=sum; ++j) t[0][j] = false;
    
    // Logic
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

int main(){
    int items[] = {3, 34, 4, 12, 5, 2};
    // int sum = 30;
    int sum = 9;
    int n = sizeof(items)/sizeof(int);

    if(isSubsetSum(n,items,sum)){
        cout<<"Sum is reachable!"<<endl;
    }else{
        cout<<"Sum is NOT reachable!"<<endl;
    }
    return 0;
}