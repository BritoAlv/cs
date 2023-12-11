// Problem: C. Insert and Equalize
// Contest: Codeforces - Educational Codeforces Round 159 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1902/problem/C
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
#define pb push_back

using namespace std;

int mcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    if (a == 1 || b == 1)
    {
        return 1;
    }
    else if (a <= b)
    {
        if (b % a == 0)
        {
            return a;
        }
        return mcd(a, b % a);
    }
    else
    {
        if (a % b == 0)
        {
            return b;
        }
        return mcd(b, a % b);
    }
}

int mcd(vector<int> &di)
{
    if (di.size() == 1)
    {
        return di[0];
    }
    else
    {
        int mcdd = di[0];
        for (int i = 1; i < di.size(); i++)
        {
            mcdd = mcd(mcdd, di[i]);
        }
        return mcdd;
    }
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    set<int> values;
    forn
    {
        cin >> a[i];
        values.insert(a[i]);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    vector<int> difs;
    for (int i = 1; i < n; i++)
    {
        difs.pb(abs(a[i] - a[i - 1]));
    }
    int mcdd = mcd(difs);
    long long ans = 0;
    int new_number = *(values.rbegin());
    while (values.find(new_number) != values.end())
    {
        new_number -= mcdd;
        ans += 1;
    }
    forn
    {
        ans += (*values.rbegin() - a[i]) / mcdd;
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