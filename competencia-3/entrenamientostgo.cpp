#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    //n numero de miradore
    // x ctda de metro q esta dispuesto a subir de un mirador al sgte 
    // en cada valor del vector altura del mirador van creciendo 
    int n, x;
    cin >> n >> x;
    vector <int> distancias(n);
    for (int i=0; i<n; i++){
        cin >> distancias[i]; //vector con las distancias 
    }
    vector <int> miradores(n, 1);

    if (n==1){
        cout << 1 << endl;
        return 0;
    }

    int c=0;
    for (int i=0; i<n-1; i++){
        if (distancias[i+1]-distancias[i]<= x){//si es que puede ir al sgte
            miradores[c]= miradores[c]+1;
        } 
        else{
            c=i+1;
        }
    }
    int max=0;
    for (int i=0; i <n; i++){
        if(miradores[i]>max){
            max=miradores[i];
        } 
    }
    cout << max << endl;
    
}
