// Problem: E. Long Inversions
// Contest: Codeforces - Codeforces Round 938 (Div. 3)
// URL: https://codeforces.com/contest/1955/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Math Proof:
/*
Notar que ( a => x, b => x ) => (a => b), porque la operación siempre se puede revertir, entonces si se puede transformar en 11111, se puede transformar en 11100, pero se una forma de transformar a el string a 111**, si ** no es 11 o 00 entonces no se puede
*/
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

struct FenwickTreeOneBasedIndexing
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a) : FenwickTreeOneBasedIndexing(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    void range_add(int l, int r, int val)
    {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};

int w(int k, string &s)
{
    int n = s.size();
    FenwickTreeOneBasedIndexing ft(vector<int>(n + 1, 0));
    for (int i = 0; i <= n - k; i++)
    {
        if ((int(s[i] - '0') + ft.point_query(i + 1)) % 2 == 0)
        {
            ft.range_add(i + 1, i + k, 1);
        }
    }
    int val = (int(s[n - k] - '0') + ft.point_query(n - k + 1)) % 2;
    for (int i = n - k + 1; i < n; i++)
    {
        if ((int(s[i] - '0') + ft.point_query(i + 1)) % 2 != val)
        {
            return 0;
        }
    }
    return 1;
}

void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = n; i >= 1; i--)
    {
        if (w(i, s))
        {
            cout << i << endl;
            return;
        }
    }
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
