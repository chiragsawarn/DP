// GFG Accepted
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
#include <bits/stdc++.h>
using namespace std;

bool isSubsetSumReachable(int items[], int n, int sum){
    bool t[2][sum+1];
    // initialization
    // 1. sum = 0  is always attainable
    t[0][0] = true;
    t[1][0] = true;
    // 2. No sum is attainable when no items are available 
    for(int j=1; j<=sum; ++j) t[0][j] = false;
    
    // Logic
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=sum; ++j){
            if(items[i-1] <= j){
                bool included = t[(i+1)%2][j-items[i-1]];
                bool excluded = t[(i+1)%2][j];
                t[i%2][j] = (included || excluded);
            }else{
                bool excluded = t[(i+1)%2][j];
                t[i%2][j] = excluded;
            }
        }
    }

    return t[n%2][sum];
}

int main(){
    int items[] = {3, 34, 4, 12, 5, 2};
    // int sum = 30;
    int sum = 9;
    int n = sizeof(items)/sizeof(int);

    if(isSubsetSumReachable(items,n,sum)){
        cout<<"Sum is reachable!"<<endl;
    }else{
        cout<<"Sum is NOT reachable!"<<endl;
    }
    return 0;
}