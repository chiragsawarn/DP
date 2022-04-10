// GFG NOT Accepted
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/#
#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

int cutRod(int price[], int n, int capacity) {
    if(n == 0 || capacity == 0) return 0;
    if(t[n][capacity] != -1) return t[n][capacity];

    if(n <= capacity){
        int included = price[n-1] + cutRod(price,n,capacity-n);
        int excluded = cutRod(price,n-1,capacity);
        t[n][capacity] = max(included,excluded);
        return t[n][capacity];
    }else{
        int excluded = cutRod(price,n-1,capacity);
        t[n][capacity] = excluded;
        return t[n][capacity];
    }
}

int main(){
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(p)/sizeof(int);
    memset(t,-1,sizeof(t));
    cout<<cutRod(p,n,n)<<endl;
    return 0;
}