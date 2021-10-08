#include <bits/stdc++.h>

using namespace std;

int prim(vector<vector<int>> &adj_matrix, int n, vector<int> &ll, vector<bool> &visited) {
    int mn=INT_MAX, mn_index=ll[0];
    for(auto root1:ll) {
        for(int i=0; i<n; i++) {
            if(!visited[i] and adj_matrix[root1][i]!=0) {
                if(mn>=adj_matrix[root1][i]) {
                    mn = adj_matrix[root1][i];
                    mn_index = i;
                }
            }
        }
    }
    if(mn==INT_MAX) return 0;
    ll.push_back(mn_index);
    visited[mn_index] = true;
    return mn+prim(adj_matrix, n, ll, visited);
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
    vector<bool> visited(n, false);
    visited[0]=true;
    vector<int> ll;
    ll.push_back(0);
    cout<<prim(adj_matrix, n, ll, visited);
}