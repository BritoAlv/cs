// Problem: C. Summarize to the Power of Two
// Contest: Codeforces - Codeforces Round 496 (Div. 3)
// URL: https://codeforces.com/contest/1005/problem/C
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
    int n;
    cin >> n;
    ull a[n];
    forn
    {
        cin >> a[i];
    }
    map<ull, set<int>> X;
    forn
    {
        if (X.find(a[i]) == X.end())
        {
            X[a[i]] = set<int>();
        }
        X[a[i]].insert(i);
    }
    ull pow[34];
    pow[0] = 1;
    for (int i = 1; i < 34; i++)
    {
        pow[i] = 2 * pow[i - 1];
    }
    int good_ones = 0;
    forn
    {
        for (int j = 0; j < 34; j++)
        {
            if (a[i] < pow[j])
            {
                ull couple = pow[j] - a[i];
                if (X.find(couple) != X.end())
                {
                    int holds = 0;
                    for (auto x : X[couple])
                    {
                        if (x != i)
                        {
                            holds = 1;
                            break;
                        }
                    }
                    if (holds)
                    {
                        good_ones++;
                        break;
                    }
                }
            }
        }
    }
    cout << n - good_ones << endl;
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