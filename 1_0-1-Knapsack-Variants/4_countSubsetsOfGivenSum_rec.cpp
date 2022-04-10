// GFG Accepted
// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
int m = 1000000007;

int countOfZeros(int arr[], int n){
	int count = 0;
	for(int i=0; i<n; ++i){
		if(!arr[i]) ++count;
	}
	return count;
}

int countOfSubsets(int arr[], int n, int sum){
	if(sum == 0) return 1;
	if(n == 0) return 0;
	if(t[n][sum] != -1) return t[n][sum];
	
	if(arr[n-1] <= sum){
		int included = countOfSubsets(arr,n-1,sum-arr[n-1]);
		int excluded = countOfSubsets(arr,n-1,sum);
		t[n][sum] = ((included%m)+(excluded%m))%m;
		return t[n][sum];
	}else{
		t[n][sum] = countOfSubsets(arr,n-1,sum);
		return t[n][sum];
	}
}

int perfectSum(int arr[], int n, int sum){
	int count_0 = countOfZeros(arr,n);
	int combinations = pow(2,count_0);
	int val = countOfSubsets(arr,n,sum);
	
	return ((val%m)*(combinations%m))%m;
}

int main(){
	// int a[] = {0,0,0,0,0,0,0,0,1};
	// int n = sizeof(a)/sizeof(int);
	// int sum = 1;

	// output should be 3
	int a[] = {2,3,5,6,8,10};
	int n = sizeof(a)/sizeof(int);
	int sum = 6;

	memset(t,-1,sizeof(t));

	cout<<"Count of subsets of a given sum : "<<perfectSum(a,n,sum)<<endl;
	return 0;
}