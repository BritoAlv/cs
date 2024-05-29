// Problem: B. Alyona and a Narrow Fridge
// Contest: Codeforces - Codeforces Global Round 2
// URL: https://codeforces.com/contest/1119/problem/B
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

int a[1000];
long long h;
int n;

int simulate(int k)
{
    long long copy_h = h;
    vector<int> v;
    fork
    {
        v.pb(a[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.sz; i += 2)
    {
        copy_h -= v[i];
    }
    return copy_h >= 0;
}

void Solve()
{
    cin >> n >> h;
    forn
    {
        cin >> a[i];
    }
    int st = 1;
    int ed = n;
    while (ed - st > 1)
    {
        int md = st + (ed - st) / 2;
        if (simulate(md))
        {
            st = md;
        }
        else
        {
            ed = md - 1;
        }
    }
    if (st + 1 <= n && simulate(st + 1))
    {
        st++;
    }
    cout << st << endl;
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