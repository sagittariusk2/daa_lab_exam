#include <bits/stdc++.h>

using namespace std;

void bellman_ford_algo(vector<vector<int>> &adj_matrix, vector<bool> &visited, vector<int> &distance, int n) {
    vector<pair<int, int>> edges;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(adj_matrix[i][j]!=0) {
                edges.emplace_back(i, j);
            }
        }
    }

    for(int i=1; i<n; i++) {
        for(auto j:edges) {
            int x = j.first, y = j.second;
            distance[y] = min(distance[y], distance[x]+adj_matrix[x][y]);
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
    }
    cout<<"Enter the root node : ";
    int root;
    cin>>root;
    vector<bool> visited(n, false);
    vector<int> distance(n, INT_MAX);
    distance[root] = 0;
    bellman_ford_algo(adj_matrix, visited, distance, n);
    for(int i=0; i<n; i++) {
        cout<<i<<" : "<<distance[i]<<"\n";
    }
} 