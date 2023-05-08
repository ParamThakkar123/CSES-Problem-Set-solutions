#include <bits/stdc++.h>
using namespace std;
const int N = (2*1e5)+2;
long long int arr[N];

int main(){
    long long int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long int ans = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] <= arr[i-1]){
            ans =  ans + (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }
    cout << ans << endl;
}
