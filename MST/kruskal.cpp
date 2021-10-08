#include <bits/stdc++.h>

using namespace std;

int find(int a, vector<int> &par) {
    if(par[a]!=a) {
        return find(par[a], par);
    }
    return a;
}

void unio(int a, int b, vector<int> &par) {
    int x = find(a, par);
    int y = find(b, par);
    if(x!=y) {
        par[x]=y;
    }
}

int kruskal(vector<tuple<int, int, int>> &edges, int n) {
    sort(edges.begin(), edges.end());
    int m = edges.size();
    vector<int> par(n);
    for(int i=0; i<n; i++) {
        par[i]=i;
    }
    n--;
    int ans = 0;
    for(int i=0; i<m; i++) {
        int s = get<1>(edges[i]);
        int e = get<2>(edges[i]);
        int x = find(s, par);
        int y = find(e, par);
        if(x!=y) {
            unio(s, e, par);
            n--;
            ans += get<0>(edges[i]);
        }
        if(!n) break;
    }
    return ans;
}

int main() {
    cout<<"Enter the number of nodes : ";
    int n;
    cin>>n;
    cout<<"Enter the number of edges : ";
    int m;
    cin>>m;
    cout<<"Enter "<<m<<" edges and it's weight : \n";
    vector<tuple<int, int, int>> edges;
    for(int i=0; i<m; i++) {
        int s, e, wt;
        cin>>s>>e>>wt;
        edges.emplace_back(wt, s, e);
    }

    cout<<kruskal(edges, n);
}