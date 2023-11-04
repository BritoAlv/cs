// Problem: B. Divan and a New Project
// Contest: Codeforces - Codeforces Round 757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    forn
    {
        int b;
        cin >> b;
        a[i] = {b, i};
    }
    sort(a, a + n, greater<pair<int, int>>());

    int c[n];
    int st = 1;
    long long sum = 0;
    forn
    {
        c[a[i].second] = st;
        sum += (long long)a[i].first * abs(st);
        st = -st;
        if (st > 0)
        {
            st++;
        }
    }
    cout << 2 * sum << endl;
    cout << 0 << wp;
    forn
    {
        cout << c[i] << wp;
    }
    cout << endl;
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
