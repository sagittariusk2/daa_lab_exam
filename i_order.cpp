#include <bits/stdc++.h>

using namespace std;

int i_order_statistics(int a[], int start, int end, int ith) {
    int pivot=end;
    int i = start, j = end;
    while(i!=j) {
        if(a[i]<a[pivot]) i++;
        else if(a[j]>=a[pivot]) j--;
        else {
            swap(a[i++], a[j]);
        }
    }

    swap(a[i], a[pivot]);
    if(i==ith) return a[i];
    else if(ith<i) {
        return i_order_statistics(a, start, i-1, ith);
    } else {
        return i_order_statistics(a, i+1, end, ith);
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    for(int i=0; i<n; i++) {
        cout<<i_order_statistics(a, 0, n-1, i)<<"\n";
    }
}