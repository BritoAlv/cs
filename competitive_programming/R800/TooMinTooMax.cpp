// Problem: A. Too Min Too Max
// Contest: Codeforces - Codeforces Round 931 (Div. 2)
// URL: https://codeforces.com/contest/1934/problem/A
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

int a[200];

int get_sum(int i, int j, int k, int l)
{
    return abs(a[i] - a[j]) + abs(a[j] - a[k]) + abs(a[k] - a[l]) + abs(a[l] - a[i]);
}

void Solve()
{
    int n;
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int sum = get_sum(0, 1, 2, 3);
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (j != i)
            {
                sum = max(sum, get_sum(0, i, j, n - 1));
            }
        }
    }
    cout << sum << endl;
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
