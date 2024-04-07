#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m;
    cin >> n >> m;
 
    vector<int> tickets(n);
    vector<int> customers(m);
    set<pair<int, int>> sortedTickets;
 
    for(int i = 0; i < n; i++){
        cin >> tickets[i];
        sortedTickets.insert({tickets[i], i});
    }
 
    for(int i = 0; i < m; i++){
        cin >> customers[i];
    }
 
    for(int i = 0; i < m; i++){
        auto match = sortedTickets.lower_bound({customers[i] + 1, 0});
        if(match == sortedTickets.begin()){
            cout << -1 << endl;
        }
        else{
            match--;
            cout << (*match).first << endl;
            sortedTickets.erase(match);
        }
    }
}
