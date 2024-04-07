#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n, x;
    cin >> n >> x;
 
    vector<int> arr(n);
 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int num = 0;
    int i = 0, j = n - 1;
    while(i <= j){
        if(arr[i] + arr[j] <= x){
            i++;
            j--;
            num++;
        }
        if(arr[i] + arr[j] > x){
            j--;
            num++;
        }
    }
 
    cout << num << endl;
}
