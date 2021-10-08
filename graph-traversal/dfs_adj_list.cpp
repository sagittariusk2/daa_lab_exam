#include <bits/stdc++.h>

using namespace std;

void dfs(vector<set<int>> &adj_list, int root) {
    cout<<root<<" ";
    if(!adj_list[root].empty()) {
        for(auto i:adj_list[root]) {
            adj_list[i].erase(root);
            dfs(adj_list, i);
        }
    }
}

int main() {
    cout<<"Enter the number of nodes : ";
    int n;
    cin>>n;
    cout<<"Enter the number of edges : ";
    int m;
    cin>>m;
    cout<<"Enter "<<m<<" edges and : \n";
    vector<set<int>> adj_list(n);
    for(int i=0; i<m; i++) {
        int x, y;
        cin>>x>>y;
        adj_list[x].insert(y);
        adj_list[y].insert(x);
    }
    cout<<"Enter the root node : ";
    int root;
    cin>>root;

    dfs(adj_list, root);
}