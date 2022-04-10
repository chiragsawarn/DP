// GFG Accepted
// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
#include <bits/stdc++.h>
using namespace std;

bool isSubsetSumPossible(int items[], int n, int sum){
	int t[n+1][sum+1];
	// Initialize

	for(int i=0; i<=n; ++i) t[i][0] = true;
	for(int j=1; j<=sum; ++j) t[0][j] = false;

	// Logic
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=sum; ++j){
			if(items[i-1] <= j){
				bool included = t[i-1][j-items[i-1]];
				bool excluded = t[i-1][j];
				t[i][j] = (included || excluded);
			}else{
				bool excluded = t[i-1][j];
				t[i][j] = excluded;
			}
		}
	}

	return t[n][sum];
}

bool equalPartition(int n, int items[]){
	int sumOfAll = accumulate(items,items+n,0);
	if(sumOfAll&1) return false;
	int required_sum = sumOfAll/2;

	return isSubsetSumPossible(items,n,required_sum);
}

int main(){
	int items[] = {1, 5, 11, 5};
	int n = sizeof(items)/sizeof(int);
	if(equalPartition(n,items)){
		cout<<"\nEqual Subset Sum Partition is Possible !"<<endl;
	}else{
		cout<<"Not Possible!"<<endl;
	}
	return 0;
}