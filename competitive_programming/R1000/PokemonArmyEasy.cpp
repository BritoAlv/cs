// Problem: C1. Pokémon Army (easy version)
// Contest: Codeforces - Codeforces Round 672 (Div. 2)
// URL: https://codeforces.com/contest/1420/problem/C1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int n, q;
    cin >> n >> q;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    pair<long long, long long> odd[n];
    pair<long long, long long> ev[n];
    odd[0] = {a[0], a[0]};
    ev[0] = {0, -1};
    for (int i = 1; i < n; i++)
    {
        odd[i].first = odd[i - 1].first;
        odd[i].second = odd[i - 1].second;
        ev[i].first = ev[i - 1].first;
        ev[i].second = ev[i - 1].second;
        if (odd[i].second < a[i])
        {
            odd[i].first -= odd[i].second;
            odd[i].second = a[i];
            odd[i].first += a[i];
        }
        if (ev[i - 1].first + a[i] > odd[i].first)
        {
            odd[i].first = ev[i - 1].first + a[i];
            odd[i].second = a[i];
        }

        if (ev[i].second > a[i])
        {
            ev[i].first += ev[i].second;
            ev[i].first -= a[i];
            ev[i].second = a[i];
        }

        if (odd[i - 1].first - a[i] > ev[i].first)
        {
            ev[i].first = odd[i - 1].first - a[i];
            ev[i].second = a[i];
        }
    }
    cout << odd[n - 1].first << endl;
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
