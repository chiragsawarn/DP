#include <bits/stdc++.h>
using namespace std;

int lcs(string &x, string &y, int len_x, int len_y){
    int t[2][2];
    
    t[0][0] = 0;
    t[1][0] = 0;
    t[0][1] = 0;
    t[1][1] = 0;

    for(int i=1; i<=len_x; ++i){
        for(int j=1; j<=len_y; ++j){
            if(x[i-1] == y[j-1]){
                t[i%2][j%2] = 1 + t[(i+1)%2][(j+1)%2];
            }else{
                t[i%2][j%2] = max(t[(i+1)%2][j%2],t[i%2][(j+1)%2]);
            }
        }
    }

    return t[len_x%2][len_y%2];
}

int main(){
    string x = "abcdgh";
    string y = "abedfhr";
    cout<<lcs(x,y,x.length(),y.length())<<endl;
    return 0;
}