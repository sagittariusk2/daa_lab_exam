#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    double x = (double)a.first/(double)a.second;
    double y = (double)b.first/(double)b.second;
    return (x>y);
}

int fractional_knapsack(vector<pair<int, int>> &val_wt, int W) {
    sort(val_wt.begin(), val_wt.end(), comp);
    int ans = 0;
    for(int i=0; i<val_wt.size(); i++) {
        if(W-val_wt[i].second>=0) {
            ans += val_wt[i].first;
            W -= val_wt[i].second;
        } else {
            ans += (val_wt[i].first*W)/val_wt[i].second;
            break;
        }
    }
    return ans;
}

int main() {
    int n, W;
    cin>>n>>W;
    vector<pair<int, int>> val_wt;
    for(int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        val_wt.emplace_back(x, y);
    }

    cout<<fractional_knapsack(val_wt, W);
}