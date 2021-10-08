#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &adj_matrix, int root) {
    int n = adj_matrix.size();
    queue<int> q1;
    vector<bool> visited(n, false);
    q1.push(root);
    visited[root] = true;
    while(!q1.empty()) {
        int x = q1.front();
        q1.pop();
        cout<<x<<" ";
        for(int i=0; i<n; i++) {
            if(!visited[i] and adj_matrix[x][i]!=0) {
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
    cout<<"Enter "<<m<<" edges and it's weight : \n";
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
    for(int i=0; i<m; i++) {
        int x, y, z;
        cin>>x>>y>>z;
        adj_matrix[x][y] = z;
        adj_matrix[y][x] = z;
    }
    cout<<"Enter the root node : ";
    int root;
    cin>>root;

    bfs(adj_matrix, root);
}