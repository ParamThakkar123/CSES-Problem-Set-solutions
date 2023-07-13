#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b;
    map<long long, long long> mp;
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        
        mp[a]++;
        mp[b]--;
    }
    
    int ans = 0, maxo = 0;
    for(auto x : mp){
        ans += x.second;
        maxo = max(maxo, ans);
    }
    
    cout << maxo << endl;

}