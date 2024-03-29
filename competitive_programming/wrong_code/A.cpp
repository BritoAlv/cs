// Problem: A. Almost Increasing Subsequence
// Contest: Codeforces - Codeforces Round 869 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1817/A
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

void Solve()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> seg2(n, -1);
    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2])
        {
            int start = i;
            int end = i + 2;
            while (end + 1 < n && a[end] >= a[end + 1])
            {
                end++;
            }
            i = end;
            seg2[start] = end;
        }
    }
    while (q > 0)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int segs2 = 0;
        int cover = 0;
        forn
        {
            if ((seg2[i] >= l + 2 && seg2[i] <= r) || (seg2[i] >= 0 && i <= r - 2 && i >= l))
            {
                cover += (min(seg2[i], r) - max(i, l)) + 1;
                segs2++;
            }
        }
        cout << (r - l + 1 - cover) + 2 * segs2 << endl;
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