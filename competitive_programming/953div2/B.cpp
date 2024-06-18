// Problem: B. New Bakery
// Contest: Codeforces - Codeforces Round 953 (Div. 2)
// URL: https://codeforces.com/contest/1978/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

long long n, a, b;
long long profit(long long k)
{
    return a * (n - k) + b * (k) + k - (k * (k + 1)) / 2;
    // a*n + k( -a + b + 1 - (k+1)/2 )
    // ( -a + b + 1 - (k+1)/2 ) + k(-1/2)
    // ( -a + b + 1 - k  -1/2)
    // k = -a + b + 1 - 1/2
}

void Solve()
{
    cin >> n >> a >> b;
    long long lk = 0;
    long long gk = min(n, b);
    vector<long long> cands;
    cands.pb(profit(lk));
    cands.pb(profit(gk));
    for (long long i = max(0ll, -a + b + 1 - 3); i <= min(min(n, b), max(0ll, -a + b + 1) + 3ll); i++)
    {
        cands.pb(profit(i));
    }
    sort(cands.begin(), cands.end());
    cout << cands.back() << endl;

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