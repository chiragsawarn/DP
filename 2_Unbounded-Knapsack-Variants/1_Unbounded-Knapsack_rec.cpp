// GFG Acccepted
// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1/#

#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

int knapSack(int n, int capacity, int p[], int wt[]){
    if(n == 0 || capacity == 0) return 0;
    if(t[n][capacity] != -1) return t[n][capacity];
    
    if(wt[n-1] <= capacity){
        int included = p[n-1] + knapSack(n,capacity-wt[n-1], p, wt);
        int excluded = knapSack(n-1,capacity, p, wt);
        t[n][capacity] = max(included, excluded);
        return t[n][capacity];
    }else{
        int excluded = knapSack(n-1,capacity, p, wt);
        t[n][capacity] = excluded;
        return t[n][capacity];
    }
}

int main(){
    int N = 2, W = 3;
    int val[] = {1, 1};
    int wt[] = {2, 1};

    memset(t,-1,sizeof(t));

    cout<<knapSack(N,W,val,wt);
    return 0;
}