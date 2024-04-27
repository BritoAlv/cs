// Problem: B. Funny Permutation
// Contest: Codeforces - Codeforces Round 826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/B
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

void Solve()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << -1 << endl;
        return;
    }
    int pt = n - 1;
    vector<int> p(n);
    p[n / 2 - ((n - 1) % 2)] = n;
    for (int i = n / 2 - ((n - 1) % 2) - 1; i >= 0; i--)
    {
        p[i] = pt--;
    }
    for (int i = n / 2 - ((n - 1) % 2) + 1; i < n; i++)
    {
        p[i] = pt--;
    }
    forn
    {
        cout << p[i] << wp;
    }
    cout << endl;
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
