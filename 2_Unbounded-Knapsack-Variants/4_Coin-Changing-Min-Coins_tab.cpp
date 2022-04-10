// Important question with Special initialization
#include <bits/stdc++.h>
using namespace std;

int minCoins(int a[], int n, int amount){
    int t[n+1][amount+1];
    for(int i=0; i<=n; ++i)
        t[i][0] = 0;
    for(int j=1; j<=amount; ++j)
        t[0][j] = INT_MAX-1;
    for(int j=1; j<=amount; ++j)
        t[0][j] = (j%a[0] == 0) ? j/a[0] : INT_MAX-1;
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=amount; ++j){
            if(a[i-1] <= j){
                int included = 1 + t[i][j-a[i-1]];
                int excluded = t[i-1][j];
                t[i][j] = min(included,excluded);
            }else{
                int excluded = t[i-1][j];
                t[i][j] = excluded;
            }
        }
    }
    return (t[n][amount] == INT_MAX || t[n][amount] == INT_MAX-1) ? -1 : t[n][amount];
}

int main(){
    int coins[] = {9, 6, 5, 1};
    int n = sizeof(coins)/sizeof(int);
    int amount = 11;
    cout<<"Minimum coins required to change : "<<minCoins(coins,n,amount)<<endl;
    return 0;
}