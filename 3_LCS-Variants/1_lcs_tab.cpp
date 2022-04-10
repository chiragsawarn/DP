#include <bits/stdc++.h>
using namespace std;

int lcs(string &x, string &y, int len_x, int len_y){
    int t[101][101];
    
    for(int i=0; i<=len_x; ++i) t[i][0] = 0;
    for(int j=1; j<=len_y; ++j) t[0][j] = 0;

    for(int i=1; i<=len_x; ++i){
        for(int j=1; j<=len_y; ++j){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    return t[len_x][len_y];
}

int main(){
    string x = "abcdgh";
    string y = "abedfhr";
    cout<<lcs(x,y,x.length(),y.length())<<endl;
    return 0;
}