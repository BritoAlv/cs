// Problem: F. Cutting Game
// Contest: Codeforces - Codeforces Round 946 (Div. 3)
// URL: https://codeforces.com/contest/1974/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

pi reverse(pi A)
{
    return {A.second, A.first};
}

void Solve()
{
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    set<pi> rows;
    set<pi> columns;
    forn
    {
        int x, y;
        cin >> x >> y;
        rows.insert({x, y});
        columns.insert({y, x});
    }
    int stR = 1;
    int stC = 1;
    int edR = a;
    int edC = b;
    int bob = 0;
    int ali = 0;
    int turn = 1;
    form
    {
        vector<pi> chips;
        char o;
        int k;
        cin >> o >> k;
        if (o == 'D')
        {
            // remove last k rows;
            auto pt = rows.lower_bound({edR - k + 1, -1});
            while (pt != rows.end())
            {
                chips.pb(*pt);
                pt++;
            }
            for (auto x : chips)
            {
                rows.erase(x);
                columns.erase(reverse(x));
            }
            edR -= k;
        }
        else if (o == 'U')
        {
            // remove first  k rows;
            auto pt = rows.lower_bound({stR, -1});
            while (pt != rows.end() && (*pt).first <= stR + k - 1)
            {
                chips.pb(*pt);
                pt++;
            }
            for (auto x : chips)
            {
                rows.erase(x);
                columns.erase(reverse(x));
            }
            stR += k;
        }
        else if (o == 'L')
        {
            // remove first k columns;
            auto pt = columns.lower_bound({stC, -1});
            while (pt != columns.end() && (*pt).first <= stC + k - 1)
            {
                chips.pb(*pt);
                pt++;
            }
            for (auto x : chips)
            {
                columns.erase(x);
                rows.erase(reverse(x));
            }
            stC += k;
        }
        else if (o == 'R')
        {
            // remove last k rows;
            auto pt = columns.lower_bound({edC - k + 1, -1});
            while (pt != columns.end())
            {
                chips.pb(*pt);
                pt++;
            }
            for (auto x : chips)
            {
                columns.erase(x);
                rows.erase(reverse(x));
            }
            edC -= k;
        }
        if (turn)
        {
            ali += chips.sz;
        }
        else
        {
            bob += chips.sz;
        }
        turn = !turn;
    }
    cout << ali << wp << bob << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
