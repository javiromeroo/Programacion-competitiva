#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n; 
    unsigned long long mod;
    mod = (1e9)+7;
	vector <vector <char> > entrada(n, vector <char> (n));
    //recorremos la matriz y la llenamos con el input de characteres
    for(int i=0; i< n; i++){
        for(int j=0; j< n; j++){
            cin >> entrada[i][j]; 
        }
    } 
    //ahora entrada tiene los puntos y asteriscos 
	vector <vector <unsigned long long> > respuestas(n, vector <unsigned long long> (n));
	for(int i = 0; i < n; i++){
        if (entrada[i][0] == '.'){
            respuestas[i][0] = 1; //distancia 1
        } 
        else if (entrada[i][0] == '*'){
            respuestas[i][0] = 0; //para indicar bomba 
            for(int k = i ; k <n; k++){ //si hay un cero rellenar lo q queda con 0s
                respuestas[k][0] = 0;
            }
            break;
        }
	}
	
	for(int j = 0; j <n; j++){
        if (entrada[0][j] == '.'){
            respuestas[0][j] = 1; //distancia 1 caso base 
        } 
        else if (entrada[0][j] == '*'){
            respuestas[0][j] = 0; //para indicar bomba 
            for(int k = j ; k <n; k++){ //si hay un cero rellenar lo q queda con 0s
                respuestas[0][k] = 0;
            }
            break;
        }
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
            if (entrada[i][j] == '*'){ 
                //si hay una bomba 
                respuestas[i][j]= 0; //indicamos eso 
            }
            else{ //si no hacemos la recursion
                respuestas[i][j] = (((respuestas[i-1][j]) % mod) + ((respuestas[i][j - 1])%mod)) % mod; 
            }
		}
	}

    if(entrada[0][0]== '*'){
        cout << 0 << endl;
    } 
    else{
        cout << (respuestas[n-1][n-1]) << endl;
    }
	return 0;
}