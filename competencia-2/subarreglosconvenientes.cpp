#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;



int sepuede(vector<long long> a, long long n, long long k, long long x) {
    long long subarreglos = 1;
    long long suma = 0;
    for (long long i = 0; i < n; i++) {
        if (a[i] > x){
            return false;
        }
    }    
    for (int i = 0; i < n; i++) {
        suma += a[i];
        if (suma > x) {
            subarreglos++;
            suma = a[i];
        }
    }
    return subarreglos <= k;
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long l, r;
    l = 1;
    r = 1e14*2; 
    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (sepuede(a, n, k, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}