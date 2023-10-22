#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

bool sepuede(vector<long long> k, long long n, long long t, long long tiempo){
    long long paquetes= 0; 
    for(long long i =0; i<n; i++){
        paquetes+= tiempo /k[i];
        if (paquetes >= t){
            return true;
        }
    }    
    return false;
}
int main(){
    long long n, t;
    cin >> n>> t;
    vector<long long> k(n);
    for (long long i=0; i<n; i++){
        cin >> k[i];
    } 
    long long izq=1, der=pow(10,18);
    while(izq < der){
        long long med = izq+((der-izq)/2);
        if(sepuede(k,n,t,med)){ //f es la funcion q nos da verdadero o falso
            der=med; //si es V descartamos la mitad derecha 
        }
        else{
            izq=med+1; //si es F descartamos la mitad izq
        }
    }
    cout << izq << endl;
    return 0;
}