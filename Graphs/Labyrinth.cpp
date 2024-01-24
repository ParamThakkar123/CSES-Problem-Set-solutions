#include <bits/stdc++.h>
using namespace std;

char A[1000][1000];
bool vis[1000][1000];

int prevStep[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string stepDir = "URDL";

int main(){
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    pair<int, int> beg, en;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
            if(A[i][j] == 'A'){
                beg = make_pair(i, j);
            }
            if(A[i][j] == 'B'){
                en = make_pair(i, j);
            }
        }
    }

    q.push(beg);
    vis[beg.first][beg.second] = true;

    while(!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            pair<int, int> v= make_pair(u.first + dx[i], u.second + dy[i]);
            if(v.first < 0 || v.first >= n || v.second < 0 || v.second >= m){
                continue;
            }
            if(A[v.first][v.second] == '#'){
                continue;
            }
            if(vis[v.first][v.second]) continue;
            vis[v.first][v.second] = true;
            prevStep[v.first][v.second] = i;
            q.push(v);
        }
    }

    if(vis[en.first][en.second]){
        cout << "YES" << endl;
        vector<int> steps;
        while(en != beg){
            int p = prevStep[en.first][en.second];
            steps.push_back(p);
            en = make_pair(en.first - dx[p], en.second - dy[p]);
        }
        reverse(steps.begin(), steps.end());
        cout << steps.size() << endl;
        for(char c : steps){
            cout << stepDir[c];
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
