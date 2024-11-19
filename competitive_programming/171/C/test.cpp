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
    vector<int> s(n);
    forn{
        char x;
        cin >> x;
        s[i] = x == '1';
    }
    ll total = ((ll)n * (n + 1)) / 2;
    ll ans = total;
    ll c_sum = 0;
    stack<int> pending;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 1) {
            c_sum += (i+1);
            pending.push(1);
            if(i >= pending.size()) {
                ans = total - c_sum;
            }
        }
        else if(pending.size() > 0) {
            pending.pop();
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}