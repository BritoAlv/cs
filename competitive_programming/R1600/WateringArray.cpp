// Problem: C. Watering an Array
// Contest: Codeforces - Codeforces Round 917 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1917/C
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

int cheq(int n, int a[])
{
    int eq = 0;
    forn
    {
        eq += a[i] == i + 1;
    }
    return eq;
}

void Solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> seq(k);
    for (int i = 0; i < k; i++)
    {
        cin >> seq[i];
    }
    int ans = 0;
    for (int dbz = 0; dbz < min(2 * n, d); dbz++)
    {
        int eq = cheq(n, a);
        int to_sum = (d - 1 - dbz) / 2;
        ans = max(ans, eq + to_sum);
        for (int i = 0; i < seq[dbz % k]; i++)
        {
            a[i]++;
        }
    }
    cout << ans << endl;
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
