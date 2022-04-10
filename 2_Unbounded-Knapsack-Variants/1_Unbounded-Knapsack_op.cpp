// GFG Acccepted
// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1/#

#include <bits/stdc++.h>
using namespace std;

int knapSack(int n, int capacity, int p[], int wt[]){
    int t[2][1001];
    t[0][0] = 0;
    t[1][0] = 0;
    for(int j=1; j<=capacity; ++j){
        t[0][j] = 0;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=capacity; ++j){
            if(wt[i-1] <= j){
                t[i%2][j] = max(p[i-1] + t[i%2][j-wt[i-1]], t[(i+1)%2][j]);
            }else{
                t[i%2][j] = t[(i+1)%2][j];
            }
        }
    }
    return t[n%2][capacity];
}

int main(){
    int N = 2, W = 3;
    int val[] = {1, 1};
    int wt[] = {2, 1};
    cout<<knapSack(N,W,val,wt);
    return 0;
}