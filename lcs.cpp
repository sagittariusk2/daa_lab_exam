#include<bits/stdc++.h>

using namespace std;

int lcs_recurssion(string str1, string str2, int n, int m, vector<vector<int>> &dp) {
    if(dp[n][m]!=-1) return dp[n][m];
    int ans;
    if(n==0 or m==0) ans = 0;
    else if(str1[n-1]==str2[m-1]) ans = 1+lcs_recurssion(str1, str2, n-1, m-1, dp);
    else {
        ans = max(lcs_recurssion(str1, str2, n-1, m, dp), lcs_recurssion(str1, str2, n, m-1, dp));
    }
    dp[n][m] = ans;
    return ans;
}

int lcs_tabulation(string str1, string str2) {
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i==0 || j==0) dp[i][j]=0;
            else if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    string str1, str2;
    cin>>str1>>str2;

    vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1, -1));
    cout<<lcs_recurssion(str1, str2, str1.length(), str2.length(), dp)<<"\n";
    cout<<lcs_tabulation(str1, str2)<<"\n";
}