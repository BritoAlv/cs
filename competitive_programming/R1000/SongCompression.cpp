// Problem: C. Songs Compression
// Contest: Codeforces - Codeforces Round 501 (Div. 3)
// URL: https://codeforces.com/contest/1015/problem/C
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
    ull m;
    cin >> n >> m;
    ull sum = 0;
    vector<int> cm;
    forn
    {
        int a, b;
        cin >> a >> b;
        sum += a;
        cm.pb(a - b);
    }
    sort(cm.begin(), cm.end());
    stack<int> v;
    forn
    {
        v.push(cm[i]);
    }
    int needed = 0;
    while (sum > m)
    {
        if (v.size() == 0)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            sum -= v.top();
            v.pop();
            needed++;
        }
    }
    cout << needed << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
