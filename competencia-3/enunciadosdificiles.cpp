//caso baso reccorer y si no hay h a r o d simplemente imprimir 0
//dp(n)= minimo costo de resolver considerando las primeras n letras 
//dp(n, p) lo mismo pero estan los primeros p caracteres de hard 
//cuando estemos en dp(n, p) tenemos los sgtes casos 

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin >> n; 
    
    vector<char> palabra(n); //vector para guardar la palabra 
    for (int i=0; i<n; i++){
        char a;
        cin >> a;
        palabra[i]=a; //armamos la palabra
    }

    vector <long long> costos(n);
    for (int i=0; i<n; i++){
        int c;
        cin >> c; 
        costos[i]=c; //guardamos los costos 
    }
    
    vector <vector <long long> > dp(n+1, vector <long long>(4)); 

    char hard[5]={'h', 'a', 'r', 'd'};

    if(n < 4){ //caso base palabra menor a 4 
        cout << 0 << endl;
        return 0;
    } 

    for(int i=1; i<n+1; i++){
        if(palabra[i-1]!='h'){ //si lo q revisamos es distinto de h 
            dp[i][0]= dp[i-1][0]; //tal como estaba
        } 
        else{
            dp[i][0]=dp[i-1][0]+ costos[i-1]; //si encontramos la h agregamos al costo de sacarla 
        }

    } 


    for(int i=1; i<4; i++){ //desde 1 pq ya vimos la h
        for(int j=1; j<n+1; j++){
            if(hard[i]==palabra[j-1]){ //si coincide el q estamos buscando 
                dp[j][i]=min(dp[j-1][i-1], dp[j-1][i]+ costos[j-1]);//min de la otra opcion o agregar el costo

            }
            else{
                dp[j][i]=dp[j-1][i];
            }
        }
    } 
    long long result= min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3]));
    cout << result << endl;



}