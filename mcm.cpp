#include<bits/stdc++.h>

using namespace std;

int mcm_recurssion(int a[], int start, int end, vector<vector<int>> &dp) {
    if(dp[start][end]!=-1) return dp[start][end];
    if(start+1==end) {
        dp[start][end] = 0;
        return 0;
    }
    int ans = INT_MAX;
    for(int i=start+1; i<end; i++) {
        int l = mcm_recurssion(a, start, i, dp);
        int r = mcm_recurssion(a, i, end, dp);
        ans = min(ans, (a[start]*a[i]*a[end])+l+r);
    }
    dp[start][end]=ans;
    return ans;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<mcm_recurssion(a, 0, n-1, dp);
}