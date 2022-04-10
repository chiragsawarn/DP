// GFG Accepted
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

#include <bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n)  { 
    int sumAll = accumulate(arr,arr+n,0);
    int sum = (sumAll/2);
    bool t[n+1][sum+1];
    
    for(int i=0; i<=n; ++i)
        t[i][0] = 1;
    for(int j=1; j<=sum; ++j)
        t[0][j] = 0;
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=sum; ++j){
            if(arr[i-1] <= j){
                bool included = t[i-1][j-arr[i-1]];
                bool excluded = t[i-1][j];
                t[i][j] = (included || excluded);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    int s1,s2;
    for(int i=sum; i>-1; --i){
        if(t[n][i] == 1){
            s1 = i;
            break;
        }
    }
    s2 = sumAll - s1;
    return (s2-s1);
}

int main(){
	int a[] = {1, 6, 11, 5};
	int n = sizeof(a)/sizeof(int);

	cout<<"Minimum susbset sum diff : "<<minDifference(a,n)<<endl;
	return 0;
}