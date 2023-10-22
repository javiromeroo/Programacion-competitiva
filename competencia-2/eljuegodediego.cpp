#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
// n cantidad de turnos por jugar 
// k bateria q queda en el compu
// a consumo cuando juega y no esta enchufado 
// b consumo cuando juega y si esta enchufado 
// a > b 
// encontrar max ctda de turnos en la q puede terminar el juego y q le de la bateria 
// le llamamos x, corresponde a q se juega esa cantidad de turnos sin cargar y el resto cargando al final la bateria debe ser positiva y debemos haber jugado los turnos 
// definimos gasto de jugar x turnos sin cargar como G(x)= x * a + (n-x)* b 
// G(x) = x(a-b)+n*b (jugando x turnos sin cargar el compu)
// G(x) es una funcion lineal, nos sirven los x tal q G(x) < k
// queremos max el x tal q se cumple esto 
// si k queda completamente por debajo de g(x) no hay solucion retornamos -1
// dada la insterseccion de las rectas queremos encontrar el entero jus antes de la insterseccion 
// antes de la insterseccion es T dsp es F 

bool sepuede(long long x, long long a, long long b, long long n, long long k){
    long long gasto = (x*a) + ((n-x)*b);
    if (gasto < k and x<=n){
        return false; 
    }
    else{
        return true;
    }
}


void solve() {
    long long k, n, a, b;
    cin >> k >> n >> a >> b; 
    long long l=0, r=n*2;
    while(l < r){
        long long mid = (l+r)/2;
        if (mid > n){
            r= l;
        }
        else{
            if(sepuede(mid,a,b,n,k)){ 
                r=mid; 
             }
            else{
                l= mid+1;
            }
        }    
    }
    if(sepuede(l, a,b,n,k)){ 
         cout << l-1 << endl;
    }  
    else{ 
        cout << -1 << endl; //retornamos el valor 
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while (q--) solve();
    return 0;
}