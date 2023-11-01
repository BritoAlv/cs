// Problem: B. Sequence Game
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> ans;
    ans.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        ans.push_back(a[i]);
        if (a[i] < a[i - 1])
        {
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << wp;
    }
    cout << endl;
    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
