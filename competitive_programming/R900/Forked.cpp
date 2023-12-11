// Problem: A. Forked!
// Contest: Codeforces - Codeforces Round 914 (Div. 2)
// URL: https://codeforces.com/contest/1904/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

void Solve()
{
    int a, b;
    cin >> a >> b;
    int q1, q2;
    cin >> q1 >> q2;
    int k1, k2;
    cin >> k1 >> k2;
    int dx[8] = {-a, -a, a, a, -b, -b, b, b};
    int dy[8] = {b, -b, b, -b, a, -a, a, -a};
    set<pair<int, int>> ans;
    for (int i = 0; i < 8; i++)
    {
        int x = dx[i];
        int y = dy[i];

        int h1 = q1 + x;
        int h2 = q2 + y;

        for (int j = 0; j < 8; j++)
        {
            int xx = dx[j];
            int yy = dy[j];
            int h11 = k1 + xx;
            int h22 = k2 + yy;
            if (h11 == h1 && h22 == h2)
            {
                ans.insert({h1, h2});
            }
        }
    }
    cout << ans.size() << endl;
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
