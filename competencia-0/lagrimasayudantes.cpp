#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
//nos entregan un string en el cual se pueden repetir letras pero
//las letras deben ir apareciendo por primera vez en orde, ej 
//no puede venir una b antes de una a 
//imprime yes si esta bien y no si es q no 
int main(){
    string s;
    cin>>s;
    int last = 'a' - 1; //queda como ultima la anterior a la a 
    bool ok = true; 
    for (int i =0; i<s.size(); i++){
        if (s[i]> last ){ //si es sgt a la ultima guardada 
            if (s[i]- last == 1) last =s[i]; //vemos q sea la sgte directa y si es guardamos esa como last
            else {
                ok=false;//else no cumple 

            }
        }
    }
    if (ok) cout <<"YES\n";
    else cout << "NO\n";
    return 0 ;
}