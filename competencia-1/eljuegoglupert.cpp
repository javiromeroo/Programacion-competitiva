#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
using namespace std;

void solve(){
    int n;
    cin >> n;
    priority_queue<long long> pq;
    long long suma = 0;
    for (int i =0; i<n; i++){
        long long cartas;
        cin >> cartas;
        if (cartas == 0){
            if (pq.empty()){
                continue;
            }
            else{
                long long max = pq.top();
                suma+= max;
                pq.pop();
            }
        }
        else{
            pq.push(cartas);
        }
    }
    cout << suma << endl;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while (t--) solve();
    return 0;
}