#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//tenemos 2 torres con bloques de 2 colores representados por r b
//escritos abajo a arriba 
//hay q ver si se pueden ordenar tales q ningunos 2 bloques iguales queden juntos
//imprime yes  no 
void solve() {
    int n, m; //cantidad de bloques de las torres
    string s1, s2; //strings con los colores de las torres
    cin >>n>>m>>s1>>s2;
    reverse(s2.begin(), s2.end()); //damos vuelta el string para q este lo de abajo primero
    string s=s1 +s2; //creamos un string con ambas torres 
    int c =0; //contador 
    for (int i=1; i<s.size(); i++){ //mientras quede torre por recorrer 
        if (s[i] == s[i-1]) c++; //cada vez q tengamos 2 seguidos agregamos al contador 
    }
    if (c<= 1) cout << "YES\n"; //si hay uno o menos estamos ok pues ahí cortamos las torres 
    else cout<<"NO\n"; //si no no 
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while (t--) solve();
    return 0;
}