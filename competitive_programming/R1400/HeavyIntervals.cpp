// Problem: C. Heavy Intervals
// Contest: Codeforces - Pinely Round 3 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1909/C
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
    int l[n];
    set<int> r;
    long long c[n];
    forn
    {
        cin >> l[i];
    }
    sort(l, l + n);
    forn
    {
        int a;
        cin >> a;
        r.insert(a);
    }
    forn
    {
        cin >> c[i];
    }
    long long sum = 0;
    sort(c, c + n);
    ull dif[n];
    for (int i = n - 1; i >= 0; i--)
    {
        // lower r that is greater than l.
        int t = *(r.lower_bound(l[i] + 1));
        dif[i] = (ull)(t - l[i]);
        r.erase(t);
    }
    sort(dif, dif + n);
    forn
    {
        sum += dif[i] * c[n - 1 - i];
    }
    cout << sum << endl;
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