#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    pair<int, int> c_pos = {0, 0};
    pair<int, int> goal = {a, b};
    map<char, pair<int, int>> m;
    m.emplace('N', make_pair(0, 1));
    m.emplace('S', make_pair(0, -1));
    m.emplace('E', make_pair(1, 0));
    m.emplace('W', make_pair(-1, 0));
    for (int i = 0; i < 10000; i++)
    {
        if (c_pos == goal)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {

            int dx = c_pos.first + m[s[i % s.size()]].first;
            int dy = c_pos.second + m[s[i % s.size()]].second;
            c_pos = {dx, dy};
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}