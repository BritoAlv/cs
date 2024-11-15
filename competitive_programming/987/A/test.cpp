#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> b;
    forn {
        int x;
        cin >> x;
        b[x]++;
    }
    int minn = n;
    for(auto [fst, snd] : b) {
        minn = min(minn, n - snd);
    }
    cout << minn << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}