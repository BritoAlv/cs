// Problem: F. Greetings
// Contest: Codeforces - Codeforces Round 918 (Div. 4)
// URL: https://codeforces.com/contest/1915/problem/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    FenwickTree bb = FenwickTree(n);
    forn
    {
        cin >> a[i] >> b[i];
    }
    vector<pair<int, int>> A;
    vector<pair<int, int>> B;
    forn
    {
        B.pb({b[i], i});
    }
    int mapp[n];
    sort(B.begin(), B.end());
    forn
    {
        mapp[B[i].second] = i;
        A.pb({a[i], i});
    }
    sort(A.begin(), A.end());
    ull ans = 0;
    forn
    {
        int index_b = mapp[A[i].second];
        if (index_b + 1 < n)
        {
            ans += bb.sum(index_b + 1, n - 1);
        }
        bb.add(index_b, 1);
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