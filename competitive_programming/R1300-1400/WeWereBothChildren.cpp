// Problem: F. We Were Both Children
// Contest: Codeforces - Codeforces Round 886 (Div. 4)
// URL: https://codeforces.com/contest/1850/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int count[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        count[i] = 0;
    }
    forn
    {
        int a;
        cin >> a;
        if (a <= n)
        {
            count[a]++;
        }
    }
    vector<int> ans;
    for (int j = 1; j <= n; j++)
    {
        int div = 0;
        for (int i = 1; i * i <= j; i++)
        {
            if (j % i == 0)
            {
                div += count[i];
                if (j / i != i)
                {
                    div += count[j / i];
                }
            }
        }
        ans.pb(div);
    }
    int maxx = ans[0];
    forn
    {
        maxx = max(maxx, ans[i]);
    }
    cout << maxx << endl;
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
