#include <bits/stdc++.h>

using namespace std;

void floyd_warshall(vector<vector<int>> &adj_matrix, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(k!=i and j!=i) {
                    if(adj_matrix[j][i]!=INT_MAX and adj_matrix[i][k]!=INT_MAX)
                        adj_matrix[j][k] = min(adj_matrix[j][k], adj_matrix[j][i]+adj_matrix[i][k]);
                }
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
    vector<vector<int>> adj_matrix(n, vector<int>(n, INT_MAX));
    for(int i=0; i<n; i++) {
        adj_matrix[i][i]=0;
    }
    for(int i=0; i<m; i++) {
        int x, y, z;
        cin>>x>>y>>z;
        adj_matrix[x][y] = z;
    }
    floyd_warshall(adj_matrix, n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
} 