#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, x;
    cin >> n >> x;
    
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<long long>());
    long long no_gondolas = 0;
    long long second = n-1;
    
    for(int i = 0; i <= second; i++){
        if(v[i] + v[second] <= x){
            no_gondolas++;
            second--;
        }
        else{
             no_gondolas++;
        }
    }
    cout <<  no_gondolas << endl;
    
    return 0;
}
