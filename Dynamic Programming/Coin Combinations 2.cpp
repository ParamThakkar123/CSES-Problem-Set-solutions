#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
 
int main(){
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n);
    vector<int> dp(x + 1, 0);
 
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    vector<int> nextState(x + 1, 0);
    nextState[0] = 1;
 
    for(int i = n - 1; i >= 0; i--){
        vector<int> currentState(x + 1, 0);
        currentState[0] = 1;
        for(int sum = 1; sum <= x; sum++){
            int skipping = nextState[sum];
            int picking = 0;
            if(a[i] <= sum){
                picking = currentState[sum - a[i]];
            }
            currentState[sum] = (skipping + picking) % MOD;
        }
        nextState = currentState;
    }
 
    cout << nextState[x] << endl;
}
