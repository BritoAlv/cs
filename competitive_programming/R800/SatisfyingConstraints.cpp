// Problem: Satisfying Constraints
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/1920/problem/A
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
    int maxx = 1;
    int minn = 1e9;
    vector<int> difs;
    forn
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            maxx = max(maxx, b);
        }
        else if (a == 2)
        {
            minn = min(minn, b);
        }
        else
        {
            difs.pb(b);
        }
    }
    int exp_answer = minn - maxx + 1;
    for (auto x : difs)
    {
        if (x >= maxx && x <= minn)
        {
            exp_answer--;
        }
    }
    cout << max(0, exp_answer) << endl;
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
