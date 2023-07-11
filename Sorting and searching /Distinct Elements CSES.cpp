#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int arr[N];

int distinctelements(int a[],int n){
    sort(a, a+n);
    int counting = 0;
    for(int i = 0; i < n; i++){
        while(i < n - 1 && arr[i] == arr[i+1]){
            i++;
        }
        counting++;
    }
    return counting;
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cout << distinctelements(arr, n) << endl;
}
