#include<bits/stdc++.h>

using namespace std;

#define m 4

int carAssembly(int a[][m], int t[][m], int e[], int x[], int n) {
    int t1[n], t2[n];

    t1[0] = e[0]+a[0][0];
    t2[0] = e[1]+a[1][0];

    for(int i=1; i<n; i++) {
        t1[i] = min(t1[i-1]+a[0][i], t2[i-1]+t[1][i]+a[0][i]);
        t2[i] = min(t2[i-1]+a[1][i], t1[i-1]+t[0][i]+a[1][i]);
    }

    return min(t1[n-1]+x[0], t2[n-1]+x[1]);
}

int main() {
    int n;
    cin>>n;
    int a[2][4], t[2][4];
    for(int i=0; i<n; i++) {
        cin>>a[0][i];
    }
    for(int i=0; i<n; i++) {
        cin>>a[1][i];
    }
    t[1][0]=t[0][0]=0;
    for(int i=1; i<n; i++) {
        cin>>t[0][i];
    }
    
    for(int i=i; i<n; i++) {
        cin>>t[1][i];
    }

    int e[2], x[2];
    cin>>e[0]>>e[1]>>x[0]>>x[1];

    cout<<carAssembly(a, t, e, x, n);
}