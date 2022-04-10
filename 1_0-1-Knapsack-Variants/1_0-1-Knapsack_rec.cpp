// GFG - Accepted
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/
#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

int knapSack(int W, int wt[], int p[], int n) { 
    if(n == 0 || W == 0) return 0;
    if(t[n][W] != -1) return t[n][W];

    if(wt[n-1] <= W){
        int included = p[n-1] + knapSack(W-wt[n-1],wt,p,n-1);
        int excluded = knapSack(W,wt,p,n-1);
        t[n][W] = max(included,excluded);
        return t[n][W];
    }else{
        int excluded = knapSack(W,wt,p,n-1);
        t[n][W] = excluded;
        return t[n][W];
    }
}

int main(){
    int p[] = {60,100,120};
    int wt[] = {10,20,30};
    int n = sizeof(p)/sizeof(int);
    int W = 50;

    memset(t,-1,sizeof(t));
    cout<<"Maximum Profit : "<<knapSack(W,wt,p,n);

    return 0;
}