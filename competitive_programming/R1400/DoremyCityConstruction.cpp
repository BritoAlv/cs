// Problem: C. Doremy's City Construction
// Contest: Codeforces - Codeforces Global Round 24
// URL: https://codeforces.com/contest/1764/problem/C
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
#define pb push_back
#define ull unsigned long long
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ull max_split = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > a[i - 1])
        {
            max_split = max(max_split, (ull)i * (n - i));
        }
    }
    if (max_split == 0)
    {
        max_split = n / 2;
    }
    cout << max_split << endl;
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
