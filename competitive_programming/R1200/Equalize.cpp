// Problem: B. Equalize
// Contest: Codeforces - Codeforces Round 924 (Div. 2)
// URL: https://codeforces.com/contest/1928/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

int simulate(int k, vector<pair<int, int>> vv)
{
    for (int i = 0; i < vv.size(); i++)
    {
        if (i + k - 1 < vv.size())
        {
            int v = vv[i + k - 1].first;
            if (v >= vv[i].first && v <= vv[i].second)
            {
                return 1;
            }
        }
    }
    return 0;
}

void Solve()
{
    int n;
    cin >> n;
    set<pair<int, int>> A;
    forn
    {
        int a;
        cin >> a;
        A.insert({a + 1, a + n});
    }
    vector<pair<int, int>> vv;
    for (auto x : A)
    {
        vv.pb(x);
    }
    int ans_low = 1;
    int ans_gr = n;
    while (ans_gr - ans_low > 1)
    {
        int middle = (ans_gr + ans_low) / 2;
        if (simulate(middle, vv))
        {
            ans_low = middle;
        }
        else
        {
            ans_gr = middle - 1;
        }
    }
    if (simulate(ans_low + 1, vv))
    {
        cout << ans_low + 1 << endl;
    }
    else
    {
        cout << ans_low << endl;
    }
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
