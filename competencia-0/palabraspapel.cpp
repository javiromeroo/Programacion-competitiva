#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//tenemos grilla 8x8 donde hay una palabra oculta q son letras minusculas escritas de forma vertical
//casos de prueba multiples 
//las letras estan en una sola columna y es continua de inicio a fin 
//imprime una linea con la palabra oculta 
void solve() {
    string palabra;
    string letra;
    for(int i=0; i<8; i++){
        cin >> letra;
        int x=0;
        while(x!=8){
            if (letra[x] == '.'){
                x++;
            }
            else{
                break;
            }
        } 
        if (x!= 8){
            palabra+=letra[x];
        } 
    }
    cout << palabra << '\n';

    // codigo aqui :D
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while (t--) solve();
    return 0;
}