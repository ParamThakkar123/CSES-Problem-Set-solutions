#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+2;
int a[N], b[N];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    
    for(int l = 0; l < n; l++){
        cin >> a[l];
    }
    for(int l = 0; l < m; l++){
        cin >> b[l];
    }
    sort(a, a+n);
    sort(b, b+m);
    
    int ans = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(abs(a[i] - b[j]) <= k){
            i++;
            j++;
            ans++;
        }
        else{
            if(a[i] - b[j] > k){
                j++;
            }
            else{
                i++;
            }
        }
    }
    cout << ans << endl;
}
