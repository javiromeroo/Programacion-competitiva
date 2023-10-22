#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
//problema es se entrega un numero w indicando el peso en kilos de una sandia
//imprime yes si se puede dividir en 2 sandias q pesen cada una una ctda par 
//si no imprime no 
int main(){
    int w;
    cin >> w;
    if(w%2==0 && w!=2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}