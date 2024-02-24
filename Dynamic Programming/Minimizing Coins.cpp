#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
 
int main(){
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n);
    vector<int> dp(x + 1, 1e9);
 
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    dp[0] = 0;
 
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(a[j] <= i){
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
 
    cout << (dp[x] < 1e9 ? dp[x] : -1) << endl;
}
