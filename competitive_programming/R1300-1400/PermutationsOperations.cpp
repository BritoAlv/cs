// Problem: C. Permutation Operations
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/problemset/problem/1746/C
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

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<pair<int, int>> wa;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            wa.pb({a[i - 1] - a[i], i});
        }
    }
    sort(wa.begin(), wa.end());
    queue<int> index;
    for (auto x : wa)
    {
        index.push(x.second);
    }
    long long ADD[n];
    forn
    {
        ADD[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (index.size() == 0)
        {
            cout << n << wp;
        }
        else
        {
            cout << index.front() + 1 << wp;
            ADD[index.front()] += i;
            if (a[index.front()] + ADD[index.front()] >= a[index.front() - 1])
            {
                index.pop();
            }
        }
    }
    cout << endl;
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
