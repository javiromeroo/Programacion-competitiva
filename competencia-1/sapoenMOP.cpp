#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int x;
    int n;
    cin >> x >> n;
    set <int> posiciones;
    posiciones.insert(0);
    posiciones.insert(x);
    multiset<int> espacios;
    espacios.insert(x);
    for (int i=0; i<n; i++){
        int m; 
        cin >> m;
        auto sgte = posiciones.lower_bound(m);
        auto anterior = prev(sgte);
        int espacio = *sgte-*anterior;
        auto e = espacios.find(espacio);
        espacios.erase(e);
        int e1 = *sgte - m;
        int e2 = m - *anterior;
        espacios.insert(e1);
        espacios.insert(e2);
        posiciones.insert(m);
        auto fin = --espacios.end();
        cout << *fin << endl;
    }
}
