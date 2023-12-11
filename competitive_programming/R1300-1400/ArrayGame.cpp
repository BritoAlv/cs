// Problem: C. Array Game
// Contest: Codeforces - Codeforces Round 914 (Div. 2)
// URL: https://codeforces.com/contest/1904/problem/C
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

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a;
    forn
    {
        long long b;
        cin >> b;
        a.pb(b);
    }
    if (k >= 3)
    {
        cout << 0 << endl;
    }
    if (k == 1)
    {
        sort(a.begin(), a.end());
        long long min_dif = a[1] - a[0];
        for (int i = 2; i < a.size(); i++)
        {
            min_dif = min(min_dif, a[i] - a[i - 1]);
        }
        cout << min(a[0], min_dif) << endl;
    }
    if (k == 2)
    {
        sort(a.begin(), a.end());
        long long minn = a[0];
        forn
        {
            for (int j = i + 1; j < n; j++)
            {
                minn = min(minn, a[j] - a[i]);
                auto it = lower_bound(a.begin(), a.end(), a[j] - a[i]);
                if (it != a.begin())
                {
                    minn = min(minn, abs(a[j] - a[i] - *(it--)));
                }
                if (it != a.end())
                {
                    minn = min(minn, abs(a[j] - a[i] - *(it)));
                }
            }
        }
        cout << minn << endl;
    }

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
