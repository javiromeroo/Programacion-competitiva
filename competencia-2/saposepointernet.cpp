#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

bool sepuede(double d, vector<double> k, double m, double n){
    double routers = 1;
    double ultimo = k[0]+ d;
    for(int i=0; i<m; i++){
        if(abs(ultimo-k[i])>d){
            routers++;
            ultimo = k[i]+d;
        }
    } 
    return routers <= n; 
}

void solve() {
    //n es ctda de routers
    //m ctda de arboles
    double n, m;
    cin >> n >> m; 
    //vector k de las distancias de m arboles al principio del bosque
    vector<double> k(m);
    for (int i=0; i<m; i++){
        cin >> k[i];
    } 
    //vector ordenado de menor a mayor 
    sort(k.begin(), k.end());
    double l=0, r=1e6;
    double epsilon = 1e-9;
    while(r-l > epsilon){
        double mid = (l+r)/2;
        if(sepuede(mid,k,m,n)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout.precision(1);
    cout << fixed << r << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while (q--) solve();
    return 0;
}