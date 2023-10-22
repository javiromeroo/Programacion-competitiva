#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

    int n, x;
    cin >> n >> x;
    map <int, int> numeros;
    vector <int> a(n);
    for (int i =0; i < n; i++){
        cin >> a[i];
    }

    for(int i=0; i <n; i++){
        int busca = x - a[i];
        if (numeros.find(busca) != numeros.end() && numeros[busca] != i){
            int b = numeros[busca] + 1;
            cout << b << " " << i + 1<< endl;
            return 0; 
        }
        numeros[a[i]] = i;
    }
    cout << "IMPOSSIBLE" << endl;    
return 0;

}   