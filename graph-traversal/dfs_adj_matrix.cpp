#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj_matrix, vector<bool> &visited, int root, int n) {
    if(!visited[root]) {
        cout<<root<<" ";
        visited[root] = true;
        for(int i=0; i<n; i++) {
            if(adj_matrix[root][i]!=0)
                dfs(adj_matrix, visited, i, n);
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
    vector<bool> visited(n, false);
    dfs(adj_matrix, visited, root, n);
}