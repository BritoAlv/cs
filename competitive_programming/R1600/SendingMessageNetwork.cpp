// Problem: E. Sending a Sequence Over the Network
// Contest: Codeforces - Codeforces Round 826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/E
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

int a[200000];
int n;

void Solve()
{
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    vector<set<int>> tt(n, set<int>());
    forn
    {
        if (a[i] <= i)
        {
            tt[i - a[i]].insert(i);
        }
        if (i + a[i] <= n - 1)
        {
            tt[i].insert(i + a[i]);
        }
    }
    set<int> checked;
    set<int> actual;
    actual.insert(0);
    while (actual.sz > 0)
    {
        set<int> actual2;
        for (auto z : actual)
        {
            checked.insert(z);
            for (auto x : tt[z])
            {
                if (x == n - 1)
                {
                    cout << "YES" << endl;
                    return;
                }
                else
                {
                    if (checked.find(x + 1) == checked.end())
                        actual2.insert(x + 1);
                }
            }
        }
        actual = actual2;
    }
    cout << "NO" << endl;
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