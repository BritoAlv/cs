// Problem: D. Equalize the Remainders
// Contest: Codeforces - Codeforces Round 490 (Div. 3)
// URL: https://codeforces.com/contest/999/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

void Solve()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> rem(m, 0);
    set<int> bad_ones;
    forn
    {
        rem[a[i] % m]++;
    }
    form
    {
        if (rem[j] < n / m)
        {
            if (j == 0)
            {
                bad_ones.insert(m);
            }
            else
            {
                bad_ones.insert(j);
            }
        }
    }
    ull ops = 0;
    forn
    {
        if (rem[a[i] % m] > n / m)
        {
            // given a remainder a[i] % m, find to its right the first whose value is less than n/m,
            // to me it seems that only is needed to keep a list of the ones that are less than n/m,
            auto next = bad_ones.upper_bound({a[i] % m});
            int d;
            if (next == bad_ones.end())
            {
                next = bad_ones.begin();
                d = m - (a[i] % m) + *next;
            }
            else
            {
                d = (*(next)) - (a[i] % m);
            }
            rem[a[i] % m]--;
            rem[(a[i] + d) % m]++;
            if (rem[(a[i] + d) % m] == n / m)
            {
                bad_ones.erase(next);
            }
            a[i] += d;
            ops += d;
        }
    }
    cout << ops << endl;
    forn
    {
        cout << a[i] << wp;
    }
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}