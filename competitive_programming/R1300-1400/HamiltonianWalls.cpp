// Problem: C. Hamiltonian Wall
// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1766/C
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
#define ull unsigned long long
using namespace std;

char row1[200000];
char row2[200000];

void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> w;
    forn
    {
        cin >> row1[i];
    }
    forn
    {
        cin >> row2[i];
    }
    forn
    {
        if (row1[i] == 'W')
        {
            w.pb({i, 0});
        }
        if (row2[i] == 'W')
        {
            w.pb({i, 1});
        }
    }
    if (w.size() <= 1)
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < w.size() - 1; i++)
    {
        if (w[i].second == w[i + 1].second)
        {
            if ((w[i + 1].first - w[i].first) % 2 == 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if ((w[i + 1].first - w[i].first) % 2 == 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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
