// GFG - You don't have access to this problem
// https://www.geeksforgeeks.org/coin-change-dp-7/

#include <bits/stdc++.h>
using namespace std;

int t[101][101];

int maxWaysToChange(int a[], int n, int amount){
    if(amount == 0) return 1;
    if(n == 0) return 0;
    if(t[n][amount] != -1) return t[n][amount];

    if(a[n-1] <= amount){
        int included = maxWaysToChange(a,n,amount-a[n-1]);
        int excluded = maxWaysToChange(a,n-1,amount);
        t[n][amount] = included + excluded;
        return t[n][amount];
    }else{
        int excluded = maxWaysToChange(a,n-1,amount);
        t[n][amount] = excluded;
        return t[n][amount];
    }
}

int main(){
    // 1 + 1 + 1 + 1
    // 1 + 1 + 2
    // 1 + 3
    // 2 + 2
    int denominations[] = {1,2,3};
    int n = sizeof(denominations)/sizeof(int);
    int amount = 4;
    memset(t,-1,sizeof(t));
    cout<<"Maximum no of ways to change : "<<maxWaysToChange(denominations,n,amount)<<endl;
    return 0;
}