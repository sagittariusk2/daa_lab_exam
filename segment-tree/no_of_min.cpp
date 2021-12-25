#include <bits/stdc++.h>
using namespace std;

#define int long long

class segmentTree{
private:
    int size;
    vector<int> v1, mn, mx;

    int get_min(int l, int r, int p) {
        if(mx[p]<l or mn[p]>r) {
            return LLONG_MAX;
        }
        if(mn[p]>=l and mx[p]<=r) {
            return v1[p];
        }
        return min(get_min(l, r, 2*p+1), get_min(l, r, 2*p+2));
    }

    void set_index(int i) {
        v1[i] = min(v1[i*2+1], v1[i*2+2]);
        if(i!=0) set_index((i-1)/2);
    }

    void set_mn_mx(int i) {
        if(i<size/2) {
            set_mn_mx(i*2+1);
            set_mn_mx(i*2+2);
            mn[i] = mn[i*2+1];
            mx[i] = mx[i*2+2];
        } else {
            mn[i]=mx[i]=i;
        }
    }

public:
    segmentTree(int n) {
        size=0;
        if(n!=0) {
            size = pow(2, ceil(log2((double)n))+1)-1;
        }
        v1.assign(size, LLONG_MAX);
        mn.assign(size, 0);
        mx.assign(size, 0);
        set_mn_mx(0);
    }

    void set(int i, int key) {
        i = (size/2)+i;
        v1[i] = key;
        if(i!=0) set_index((i-1)/2);
    }

    int mini (int l, int r) {
        r--;
        return get_min(size/2+l, size/2+r, 0);
    }
};

signed main() {
    int n, q;
    cin>>n>>q;
    int a[n];
    segmentTree* sg = new segmentTree(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        sg->set(i, a[i]);
    }

    while(q--) {
        int x, y, z;
        cin>>x>>y>>z;
        if(x==1) sg->set(y, z);
        else cout<<sg->mini(y, z)<<"\n";
    }
}