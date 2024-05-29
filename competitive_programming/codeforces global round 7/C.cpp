// Problem: C. Permutation Partitions
// Contest: Codeforces - Codeforces Global Round 7
// URL: https://codeforces.com/contest/1326/problem/C
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

const long long MOD = 998244353;

void Solve()
{
    long long n, k;
    cin >> n >> k;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> pos;
    forn
    {
        if (a[i] > (n - k))
        {
            pos.pb(i);
        }
    }

    vector<int> difs;
    for (int i = 1; i < pos.sz; i++)
    {
        difs.pb(pos[i] - pos[i - 1] - 1);
    }
    long long ans = 1;
    for (auto x : difs)
    {
        ans *= (x + 1);
        ans %= MOD;
    }
    long long ans2 = 0;
    for (int i = n; i > n - k; i--)
    {
        ans2 += i;
    }
    cout << ans2 << wp << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
