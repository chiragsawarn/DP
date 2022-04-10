// GFG - Accepted
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/

#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

int knapSack(int W, int wt[], int p[], int n){
    // Recursion Base condn --> Iterative Initialization
    for(int i=0; i<=n; ++i){
        t[i][0] = 0;
    }
    for(int j=1; j<=W; ++j){
        t[0][j] = 0;
    }
    // Choice Diagram --> Iterative Logic
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=W; ++j){
            if(wt[i-1] <= j){
                int included = p[i-1] + t[i-1][j-wt[i-1]];
                int excluded = t[i-1][j];
                t[i][j] = max(included,excluded);
            }else{
                int excluded = t[i-1][j];
                t[i][j] = excluded;
            }
        }
    }

    return t[n][W];
}

int main(){
    int p[] = {60,100,120};
    int wt[] = {10,20,30};
    int n = sizeof(p)/sizeof(int);
    int W = 50;

    cout<<"Maximum Profit : "<<knapSack(W,wt,p,n);

    return 0;
}