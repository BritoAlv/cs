// Problem: A. Maximise The Score
// Contest: Codeforces - think-cell Round 1
// URL: https://codeforces.com/contest/1930/problem/A
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

void Solve()
{
    int n;
    cin >> n;
    ull sum = 0;
    n *= 2;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    forn
    {
        if (i % 2 == 0)
        {
            sum += a[i];
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
