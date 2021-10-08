#include<bits/stdc++.h>

using namespace std;

int knapsack_01_recurssion(int wt[], int val[], int n, int W, vector<vector<int>> &dp) {
    if(dp[n][W]!=-1) return dp[n][W];
    int ans;
    if(n==0 or W==0) ans = 0;
    else if(wt[n-1] > W) ans = knapsack_01_recurssion(wt, val, n-1, W, dp);
    else ans = max(knapsack_01_recurssion(wt, val, n-1, W, dp), knapsack_01_recurssion(wt, val, n-1, W-wt[n-1], dp)+val[n-1]);
    dp[n][W] = ans;
    return ans;
}

// space complexity O(n*W)
int knapsack_01_tabulation(int wt[], int val[], int n, int W) {
    vector<vector<int>> dp(n+1,vector<int>(W+1, 0));
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=W; j++) {
            if(i==0 or j==0) dp[i][j]=0;
            else if(wt[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]]+val[i-1]);
        }
    }
    return dp[n][W];
}

// space complexity O(W)
int knapsack_01(int wt[], int val[], int n, int W) {
    vector<int> dp(W+1, 0);
    for(int i=1; i<=n; i++) {
        for(int j=W; j>=0; j--) {
            if(wt[i-1]<=j)
                dp[j] = max(dp[j], dp[j-wt[i-1]]+val[i-1]);
        }
    }
    return dp[W];
}

// unbounded knapsack O(W)
int unbounded_knapsack(int wt[], int val[], int n, int W) {
    vector<int> dp(W+1, 0);
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=W; j++) {
            if(wt[i-1]<=j)
                dp[j] = max(dp[j], dp[j-wt[i-1]]+val[i-1]);
        }
    }
    return dp[W];
}

int main() {
    int n, W;
    cin>>n>>W;
    int val[n], wt[n];
    for(int i=0; i<n; i++)
        cin>>val[i];
    for(int i=0; i<n; i++)
        cin>>wt[i];

    vector<vector<int>> dp(n+1,vector<int>(W+1, -1));
    cout<<knapsack_01_recurssion(wt, val, n, W, dp)<<"\n";
    cout<<knapsack_01(wt, val, n, W)<<"\n";
    cout<<unbounded_knapsack(wt, val, n, W)<<"\n";
}