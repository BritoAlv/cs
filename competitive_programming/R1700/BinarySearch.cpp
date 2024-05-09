// Problem: E. Binary Search
// Contest: Codeforces - Codeforces Round 935 (Div. 3)
// URL: https://codeforces.com/contest/1945/problem/E
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

pi binary_search(vector<int> &a, int x, int stop)
{
    int l = 1;
    int r = a.sz;
    while (r - l > stop)
    {
        int md = (r + l) / 2;
        if (a[md] <= x)
        {
            l = md;
        }
        else
        {
            r = md;
        }
    }
    return {l, r};
}

void swap(int i, int j, vector<int> &a)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Solve()
{
    int n, x;
    cin >> n >> x;
    int pos_x = 0;
    vector<int> a(n + 1);
    forn
    {
        cin >> a[i + 1];
        if (a[i + 1] == x)
        {
            pos_x = i + 1;
        }
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    vector<pi> ops;
    pi bs = binary_search(a, x, 2);
    ops.pb({pos_x, bs.first});
    swap(pos_x, bs.first, a);
    if (a[bs.first + 1] < a[bs.first])
    {
        ops.pb({bs.first, bs.first + 1});
        swap(bs.first, bs.first + 1, a);
    }
    cout << ops.sz << endl;
    for (auto x : ops)
    {
        cout << x.first << wp << x.second << endl;
    }
    pi ff = binary_search(a, x, 1);
    assert(a[ff.first] == x);
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