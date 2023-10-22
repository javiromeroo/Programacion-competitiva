#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c; // recibir input 
    vector<long long> dp(n + 1, -1); // inicializar dp con -1s
    vector<int> pieces(3); //vector con los cortes posibles 
    pieces[0]=a; //ponemos los cortes en pieces
    pieces[1]=b;
    pieces[2]=c;
    
    dp[0] = 0; // caso base cuando no queda madera
    for (int i = 1; i <= n; i++) { //caso recursivo 
        for (int j = 0; j < 3; j++) {
            if (i >= pieces[j] && dp[i - pieces[j]] != -1) {
                dp[i] = max(dp[i], dp[i - pieces[j]] + 1);
            }    
        }   
    }

    cout << dp[n] << endl; // respuesta guardada aca 
    return 0;
}