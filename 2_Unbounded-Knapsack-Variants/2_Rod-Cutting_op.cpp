// GFG Accepted
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/#
#include <bits/stdc++.h>
using namespace std;

int t[2][1001];

int cutRod(int price[], int n) {
    //code here
    t[1][0] = 0;
    for(int j=0; j<=n; ++j)
        t[0][j] = 0;
        
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(i<=j){
                int inclusion = price[i-1] + t[i%2][j-i];
                int exclusion = t[(i+1)%2][j];
                t[i%2][j] = max(inclusion,exclusion);
            }else{
                t[i%2][j] = t[(i+1)%2][j];
            }
        }
    }
    return t[n%2][n];
}

int main(){
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(p)/sizeof(int);
    cout<<cutRod(p,n)<<endl;
    return 0;
}