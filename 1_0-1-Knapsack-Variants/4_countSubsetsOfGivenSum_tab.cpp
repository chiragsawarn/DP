// GFG Accepted
// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
#include <bits/stdc++.h>
using namespace std;

int m = 1000000007;

int countOfZeros(int arr[], int n){
	int count = 0;
	for(int i=0; i<n; ++i){
		if(!arr[i]) ++count;
	}
	return count;
}

int perfectSum(int arr[], int n, int sum){
	// Your code goes here
	int count_0 = countOfZeros(arr,n);
	int combinations = pow(2,count_0);
	
	int t[n+1][sum+1];
	for(int i=0; i<=n; ++i)
		t[i][0] = 1;
	for(int j=1; j<=sum; ++j)
		t[0][j] = 0;
	
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=sum; ++j){
			if(arr[i-1] <= j){
				int included = t[i-1][j-arr[i-1]];
				int excluded = t[i-1][j];
				t[i][j] = ((included%m) + (excluded%m))%m;
			}else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	
	return ((t[n][sum]%m)*(combinations%m))%m;
}

int main(){
	// int a[] = {0,0,0,0,0,0,0,0,1};
	// int n = sizeof(a)/sizeof(int);
	// int sum = 1;

	// output should be 3
	int a[] = {2,3,5,6,8,10};
	int n = sizeof(a)/sizeof(int);
	int sum = 6;

	cout<<"Count of subsets of a given sum : "<<perfectSum(a,n,sum)<<endl;
	return 0;
}