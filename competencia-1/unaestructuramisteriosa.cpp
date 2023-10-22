#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


int main(){
    int n;
    while (cin >> n){
        int v;
        int x;
        priority_queue<int> pq;
        queue<int> q;
        stack<int> s;
        bool qtipo = true;
        bool pqtipo = true;
        bool stipo = true; 
        for (int i =0; i <n; i ++){
            cin >> v >> x ;
            if (v == 1){
                q.push(x);
                pq.push(x);
                s.push(x);
            }
            else if ( (v == 2) && pq.size()!=0 && q.size()!= 0 && s.size() != 0){
                if (q.front() != x){
                    qtipo = false; 
                }
                if (pq.top() != x){
                    pqtipo = false;
                }
                if (s.top() != x){
                    stipo = false;
                }
                pq.pop();
                q.pop();
                s.pop();
            }
            else{
                pqtipo = false;
                stipo = false;
                qtipo = false; 
            }
        }
        if ((qtipo == true && pqtipo == true) || (stipo == true && pqtipo == true) || (qtipo == true && stipo == true) || (qtipo == true && pqtipo ==true && stipo == true) ){
            cout << "not sure" << endl;
        }
        else if (pqtipo == true ){
            cout << "priority queue" << endl; 
        }  
        else if (stipo == true){
            cout << "stack" << endl; 
        }
        else if (qtipo == true){
            cout << "queue" << endl; 
        }
        else{
            cout << "impossible" << endl;
        }
    } 
    return 0;
}