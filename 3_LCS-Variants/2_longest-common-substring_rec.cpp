#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string &a, string &b, int n1, int n2, int globalMax=0, int currMax=0){
    if(n1 == 0 || n2 == 0) return globalMax;
    if(a[n1-1] == b[n2-1]){
        ++currMax;
        longestCommonSubstring(a,b,n1-1,n2-1,globalMax,currMax);
    }else{
        currMax = 0;
        longestCommonSubstring(a,b,n1-1,n2,globalMax,currMax);
        longestCommonSubstring(a,b,n1,n2-1,globalMax,currMax);
    }
    globalMax = max(globalMax,currMax);
}

int main(){
    string a = "abcde";
    string b = "abfce";
    cout<<longestCommonSubstring(a,b,a.length(),b.length());
    return 0;
}