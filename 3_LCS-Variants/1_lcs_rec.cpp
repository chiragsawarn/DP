#include <bits/stdc++.h>
using namespace std;

int t[101][101];

int lcs(string &x, string &y, int len_x, int len_y){
    if(len_x == 0 || len_y == 0) return 0;
    if(t[len_x][len_y] != -1) return t[len_x][len_y];

    if(x[len_x-1] == y[len_y-1]){
        t[len_x][len_y] = 1 + lcs(x,y,len_x-1,len_y-1);
        return t[len_x][len_y];
    }else{
        int keepXdiscardY = lcs(x,y,len_x,len_y-1);
        int keepYdiscardX = lcs(x,y,len_x-1,len_y);
        t[len_x][len_y] = max(keepXdiscardY,keepYdiscardX);
        return t[len_x][len_y];
    }
}

int main(){
    string x = "abcdgh";
    string y = "abedfhr";
    memset(t,-1,sizeof(t));
    cout<<lcs(x,y,x.length(),y.length())<<endl;
    return 0;
}