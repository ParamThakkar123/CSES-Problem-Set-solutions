#include <bits/stdc++.h>
using namespace std;

vector<int> buildSuffixArray(const string &S){
    int n = S.size();
    const int alphabet = 256;

    vector<int> c(n), p(n), cnt(max(alphabet, n), 0);
    for(int i = 0; i < n; i++){
        cnt[S[i]]++;
    }

    for(int i = 1; i < alphabet; i++){
        cnt[i] += cnt[i-1];
    }

    for(int i = 0; i < n; i++){
        p[--cnt[S[i]]] = i;
    }

    c[p[0]] = 0;
    int classes = 1;
    for(int i = 1; i < n; i++){
        if(S[p[i]] != S[p[i-1]]){
            classes++;
        }
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for(int h = 0; (1 << h) < n; h++){
        for(int i = 0; i < n; i++){
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0){
                pn[i] += n;
            }
        }

        fill(cnt.begin(), cnt.begin() + classes, 0);

        for(int i = 0; i < n; i++){
            cnt[c[pn[i]]]++;
        }

        for(int i = 1; i < classes; i++){
            cnt[i] += cnt[i-1];
        }

        for(int i = n - 1; i >= 0; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }

        cnt[p[0]] = 0;
        classes = 1;

        for(int i = 1; i < n; i++){
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h) % n)]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h) % n)]};

            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> buildLCP(const string &S, const vector<int> &P){
    int N = S.size();
    vector<int> R(N, 0);

    for(int i = 0; i < N; i++){
        R[P[i]] = i;
    }

    int k = 0;
    vector<int> lcp(N - 1, 0);
    for(int i = 0; i < N; i++){
        if(R[i] == N - 1){
            k = 0;
            continue;
        }

        int j = P[R[i] + 1];
        while(i + k < N && j + k < N && S[i+k] == S[j + k]){
            k++;
        }
        lcp[R[i]] = k;
        if(k) k--;
    }
    return lcp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;
    vector<int> suf = buildSuffixArray(S);
    vector<int> lcp = buildLCP(S, suf);

    int ans = 0;
    for(int i = 0; i < S.size() - 1; i++){
        ans = max(ans, lcp[i]);
    }

    if(ans == 0){
        cout <<  -1 << endl;
        return 0;
    }

    for(int i = 0; i < S.size(); i++){
        if(ans == lcp[i]){
            cout << S.substr(suf[i], lcp[i]) << endl;
            return 0;
        }
    }
}
