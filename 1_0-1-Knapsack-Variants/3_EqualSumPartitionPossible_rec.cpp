// GFG Accepted
// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
#include <bits/stdc++.h>
using namespace std;

int t[101][101];

bool isSubsetSumPossible(int items[], int n, int sum){
    if(sum == 0) return true;
    if(n == 0) return false;
    if(t[n][sum] != -1) return t[n][sum];

    if(items[n-1] <= sum){
        bool included = isSubsetSumPossible(items,n-1,sum-items[n-1]);
        bool excluded = isSubsetSumPossible(items,n-1,sum);
        t[n][sum] = (included || excluded);
        return t[n][sum];
    }else{
        bool excluded = isSubsetSumPossible(items,n-1,sum);
        t[n][sum] = excluded;
        return t[n][sum];
    }
}

bool equalPartition(int n, int items[]){
    int sumAll = accumulate(items,items+n,0);
    if(sumAll&1) return false;
    return isSubsetSumPossible(items,n,sumAll/2);
}

int main(){
    int items[] = {478,757,314,471,729,100,459,618};
	int n = sizeof(items)/sizeof(int);
    memset(t,-1,sizeof(t));
	if(equalPartition(n,items)){
		cout<<"\nEqual Subset Sum Partition is Possible !"<<endl;
	}else{
		cout<<"Not Possible!"<<endl;
	}
	return 0;
}