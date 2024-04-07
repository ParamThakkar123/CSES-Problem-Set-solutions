#include <bits/stdc++.h>
using namespace std;
 
bool cmp(pair<int, int> &a, pair<int, int> &b){
    return (a.second < b.second);
}
 
int main(){
    int n;
    cin >> n;
 
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
 
    sort(p.begin(), p.end(), cmp);
    int i = 0;
    int endOfLastMovie = -1;
    int movies = 0;
 
    while(i < n){
        if(p[i].first >= endOfLastMovie){
            movies++;
            endOfLastMovie = p[i].second;
            i++;
        }
        else{
            i++;
        }
    }
 
    cout << movies << endl;
}
