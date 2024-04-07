#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
 
    vector<long long> arr(n);
 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
 
    long long best = INT_MIN;
    long long past = 0;
 
    for(int i = 0; i < n; i++){
        if(past + arr[i] >= arr[i]){
            past += arr[i];
        }
        else{
            past = arr[i];
        }
 
        best = max(best, past);
    }
 
    cout << best << endl;
}
