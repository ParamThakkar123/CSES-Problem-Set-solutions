#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
 
    vector<int> arr(n), sorted(n);
 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
 
    long ans = 1;
 
    // Array to store the index of numbers from 1 to N
    vector<long> indices(n + 1);
 
    // Store the index of all elements of arr[]
    for (int i = 0; i < n; i++) {
        indices[arr[i]] = i;
    }
 
    // If num occurs after (num + 1), increment ans by 1
    for (int num = 1; num < n; num++) {
        if (indices[num + 1] < indices[num])
            ans++;
    }
    cout << ans << endl;
}
