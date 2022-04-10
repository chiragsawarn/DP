// GFG NOT ACCEPTED
// Minimum sum partition 
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
// This question can not be solved using recursion.
// Reason: Recursion doesn't prepare the table the same way tabulation does.
//         And we need to look into table values in this question.

// BELOW CODE DOESN'T WORK

#include <bits/stdc++.h>
using namespace std;

int t[6][100];

void print_t(int n, int sum){
	for(int i=0; i<n; ++i){
		for(int j=0; j<sum; ++j){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isSubsetSumPossible(int a[], int n, int sum){
	if(sum == 0) return true;
	if(n == 0) return false;
	if(t[n][sum] != -1) return t[n][sum];

	if(a[n-1] <= sum){
		int included = isSubsetSumPossible(a,n-1,sum-a[n-1]);
		int excluded = isSubsetSumPossible(a,n-1,sum);
		t[n][sum] = (included || excluded);
		return t[n][sum];
	}else{
		int excluded = isSubsetSumPossible(a,n-1,sum);
		t[n][sum] = excluded;
		return t[n][sum];
	}
}

int minSubsetSumDiff(int a[], int n){
	int sumOfAll = accumulate(a,a+n,0);
	int sum = sumOfAll/2;
	isSubsetSumPossible(a,n,sum);
	print_t(n,sum);
	for(int i=sum; i >=0; --i){
		if(t[n][i] == 1){
			return sumOfAll - 2*i;
		}
	}
}

int main(){
	int a[] = {20,19,18,20,16};
	// int a[] = {1, 6, 11, 5};
	int n = sizeof(a)/sizeof(int);

	memset(t,-1,sizeof(t));

	cout<<"Minimum susbset sum diff : "<<minSubsetSumDiff(a,n)<<endl;
	return 0;
}