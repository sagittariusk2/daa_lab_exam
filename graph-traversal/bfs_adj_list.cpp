#include <bits/stdc++.h>

using namespace std;

void bfs(vector<set<int>> &adj_list, int root) {
    queue<int> q1;
    int n = adj_list.size();
    q1.push(root);
    vector<bool> visited(n, false);
    visited[root] = true;
    while(!q1.empty()) {
        int x = q1.front();
        q1.pop();
        cout<<x<<" ";
        for(auto i:adj_list[x]) {
            if(!visited[i]) {
                visited[i] = true;
                q1.push(i);
            }
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

    bfs(adj_list, root);
}