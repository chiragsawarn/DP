// GFG - You don't have access to this problem
// https://www.geeksforgeeks.org/coin-change-dp-7/

#include <bits/stdc++.h>
using namespace std;

int t[2][101];

int maxWaysToChange(int a[], int n, int amount){
    t[0][0] = 1;
    t[1][0] = 1;
    for(int j=1; j<=amount; ++j)
        t[0][j] = 0;
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=amount; ++j){
            if(a[i-1] <= j){
                int included = t[i%2][j-a[i-1]];
                int excluded = t[(i+1)%2][j];
                t[i%2][j] = included + excluded;
            }else{
                int excluded = t[(i+1)%2][j];
                t[i%2][j] = excluded;
            }
        }
    }

    return t[n%2][amount];
}

int main(){
    // 1 + 1 + 1 + 1 + 1
    // 1 + 1 + 1 + 2
    // 1 + 1 + 3
    // 1 + 2 + 2
    // 2 + 3
    int denominations[] = {1,2,3};
    int n = sizeof(denominations)/sizeof(int);
    int amount = 5;
    memset(t,-1,sizeof(t));
    cout<<"Maximum no of ways to change : "<<maxWaysToChange(denominations,n,amount)<<endl;
    return 0;
}