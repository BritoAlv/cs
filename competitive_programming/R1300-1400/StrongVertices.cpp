// Problem: D. Strong Vertices
// Contest: Codeforces - Codeforces Round 891 (Div. 3)
// URL: https://codeforces.com/contest/1857/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: notice properties of the inequality
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
    int a[n];
    int b[n];
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    vector<int> difs;
    for (int i = 0; i < n; i++)
    {
        difs.push_back(a[i] - b[i]);
    }
    sort(difs.begin(), difs.end());
    vector<int> work;
    forn
    {
        if (a[i] - b[i] == difs[n - 1])
        {
            work.push_back(i + 1);
        }
    }
    cout << work.size() << endl;
    for (auto x : work)
    {
        cout << x << wp;
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
