// Problem: B. Three Sevens
// Contest: Codeforces - Codeforces Round 860 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1798/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: what should be seven is the last seven where each
// element appears.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int m;
    cin >> m;
    unordered_map<int, int> set;
    int count = 1;
    while (count <= m)
    {
        int n;
        cin >> n;

        while (n > 0)
        {
            int t;
            cin >> t;
            set[t] = count;
            n--;
        }
        count++;
    }

    int a[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = 0;
    }

    for (auto it = set.begin(); it != set.end(); it++)
    {
        a[(*it).second - 1] = (*it).first;
    }

    for (int i = 0; i < m; i++)
    {
        if (a[i] == 0)
        {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << a[i] << wp;
    }
    cout << endl;

    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
