// Problem: C. Find B
// Contest: Codeforces - Educational Codeforces Round 162 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1923/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    int n, q;
    cin >> n >> q;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<long long> psum(n, 0);
    vector<long long> cuno(n, 0);
    forn
    {
        if (a[i] > 1)
        {
            psum[i] += (a[i] - 1);
        }
        else
        {
            cuno[i]++;
        }
        if (i > 0)
        {
            psum[i] += psum[i - 1];
            cuno[i] += cuno[i - 1];
        }
    }
    int l, r;
    while (q > 0)
    {
        cin >> l >> r;
        r--;
        l--;
        long long p1 = psum[r] - (l > 0 ? psum[l - 1] : 0);
        long long p2 = cuno[r] - (l > 0 ? cuno[l - 1] : 0);
        if (p1 >= p2 && (r > l))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        q--;
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
