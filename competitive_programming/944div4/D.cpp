// Problem: D. Binary Cut
// Contest: Codeforces - Codeforces Round 944 (Div. 4)
// URL: https://codeforces.com/contest/1971/problem/D
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    string s;
    cin >> s;
    int n = s.sz;
    vector<char> d;
    d.pb(s[0]);
    int pt = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != d[pt])
        {
            d.pb(s[i]);
            pt++;
        }
    }
    int flag = 0;
    for (int i = 1; i < d.sz; i++)
    {
        if (d[i] == '1' && d[i - 1] == '0')
        {
            flag = 1;
        }
    }
    cout << d.sz - flag << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
