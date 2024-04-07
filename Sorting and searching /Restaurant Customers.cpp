#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> events;
 
    for(int i = 0; i < n; i++){
        int arr, dep;
        cin >> arr >> dep;
        events.push_back({arr, 1});
        events.push_back({dep, -1});
    }
 
    sort(events.begin(), events.end());
    int maxCustomers = 0;
    int actualCustomers = 0;
    for(int i = 0; i < events.size(); i++){
        actualCustomers += events[i].second;
        maxCustomers = max(maxCustomers, actualCustomers);
    }
 
    cout << maxCustomers << endl;
}
