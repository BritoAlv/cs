// Problem: D. Frets On Fire
// Contest: Codeforces - Codeforces Global Round 2
// URL: https://codeforces.com/contest/1119/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

vector<long long> difs;

int get_less(long long val)
{
    if (difs.sz == 0 || difs[0] >= val)
    {
        return 0;
    }
    int st = 0;
    int ed = difs.sz - 1;
    while (ed - st > 1)
    {
        int md = st + (ed - st) / 2;
        if (difs[md] < val)
        {
            st = md;
        }
        else
        {
            ed = md - 1;
        }
    }
    if (st + 1 < difs.sz && difs[st + 1] < val)
    {
        st++;
    }
    return st + 1;
}

void Solve()
{
    int n;
    cin >> n;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<long long> prefix_difs;
    for (int i = 1; i < n; i++)
    {
        difs.pb(a[i] - a[i - 1]);
        prefix_difs.pb(a[i] - a[i - 1]);
    }
    sort(prefix_difs.begin(), prefix_difs.end());
    sort(difs.begin(), difs.end());
    for (int i = 1; i < prefix_difs.sz; i++)
    {
        prefix_difs[i] += prefix_difs[i - 1];
    }
    int q;
    cin >> q;
    while (q > 0)
    {
        long long l, r;
        cin >> l >> r;
        long long val = r - l + 1;
        long long less = get_less(val);
        long long big = n - 1 - less;
        // cout << l << wp << r << wp << val << wp << less << wp << big << endl;
        cout << (less > 0 ? prefix_difs[less - 1] : 0) + (val) * (big + 1) << wp;
        q--;
    }
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
