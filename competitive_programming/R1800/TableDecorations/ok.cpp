#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

vector<vector<int>> options = {{1, 1, 1}, {1, 0, 2}, {1, 2, 0}, {0, 2, 1}, {0, 1, 2}, {2, 0, 1}, {2, 1, 0}};

ll solve(const ll a, const ll b, const ll c)
{
    ll ans = 0;
    for (auto option : options)
        if (a >= option[0] && b >= option[1] && c >= option[2])
            ans = max(ans, 1 + solve(a - option[0], b - option[1], c - option[2]));
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
}