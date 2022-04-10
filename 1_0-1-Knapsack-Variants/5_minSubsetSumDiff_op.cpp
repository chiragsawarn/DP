// GFG Accepted
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

#include <bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n)  { 
    // Your code goes here
    int sumAll = accumulate(arr,arr+n,0);
    int sum = (sumAll/2);
    bool t[2][sum+1];
    
    t[0][0] = 1;
    t[1][0] = 1;
    for(int j=1; j<=sum; ++j)
        t[0][j] = 0;
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=sum; ++j){
            if(arr[i-1] <= j){
                bool included = t[(i+1)%2][j-arr[i-1]];
                bool excluded = t[(i+1)%2][j];
                t[i%2][j] = (included || excluded);
            }else{
                t[i%2][j] = t[(i+1)%2][j];
            }
        }
    }
    
    int s1,s2;
    for(int i=sum; i>-1; --i){
        if(t[n%2][i] == 1){
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