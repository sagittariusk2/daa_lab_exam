#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return (a.second<b.second);
}

int fractional_knapsack(vector<pair<int, int>> &activity) {
    sort(activity.begin(), activity.end(), comp);
    int ans = 0, n=activity.size(), end=-1;
    for(int i=0; i<n; i++) {
        if(i==0 or activity[i].first>=end) {
            ans++;
            end = activity[i].second;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> activity;
    for(int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        activity.emplace_back(x, y);
    }

    cout<<fractional_knapsack(activity);
}