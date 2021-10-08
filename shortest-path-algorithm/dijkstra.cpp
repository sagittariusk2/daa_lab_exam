#include <bits/stdc++.h>

using namespace std;

void dijkstras(vector<vector<int>> &adj_matrix, vector<bool> &visited, vector<int> &distance, int root, int n) {
    if(!visited[root]) {
        visited[root] = true;
        int mn=INT_MAX, min_index=root;
        for(int i=0; i<n; i++) {
            if(adj_matrix[root][i]!=0) {
                distance[i] = min(distance[i], adj_matrix[root][i]+distance[root]);
                if(mn>=distance[i]) {
                    mn = distance[i];
                    min_index = i;
                }
            }
        }
        dijkstras(adj_matrix, visited, distance, min_index, n);
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
    dijkstras(adj_matrix, visited, distance, root, n);
    for(int i=0; i<n; i++) {
        cout<<i<<" : "<<distance[i]<<"\n";
    }
} 