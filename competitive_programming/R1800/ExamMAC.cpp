// Problem: D. Exam in MAC
// Contest: Codeforces - Codeforces Round 932 (Div. 2)
// URL: https://codeforces.com/contest/1935/problem/D
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

long long as_sum(long long v, long long c)
{
    // 0 <= x <= y <= c
    // x+y = v.
    // 0 + v
    // 1 + (v-1)
    // 2 + (v-2)
    // v/2 + (v/2 + v % 2)
    if (c < v / 2 + v % 2)
    {
        return 0;
    }
    else
    {
        return v / 2 + 1 - max(0ll, v - c);
    }
    return 0;
}

long long as_dif(long long v, long long c)
{
    // 0 <= x <= y <= c
    // y-x = v
    if (c < v)
    {
        return 0;
    }
    return c - v + 1;
    // c - (c - v) = v
    // (c-1) - (c - 1 - (v)) = v
    // ....
    // v - 0 = v
    return 0;
}

void Solve()
{
    long long n, c;
    cin >> n >> c;
    long long ans = (c + 2) * (c + 1);
    ans /= 2;
    long long odds = 0;
    long long a[n];
    forn
    {
        cin >> a[i];
        odds += (a[i] % 2 == 1);
        ans -= as_sum(a[i], c);
        ans -= as_dif(a[i], c);
        ans++;
    }
    long long evens = n - odds;
    ans += (odds * (odds - 1)) / 2;
    ans += (evens * (evens - 1)) / 2;
    cout << ans << endl;
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
