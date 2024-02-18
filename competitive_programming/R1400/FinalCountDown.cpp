// Problem: E. Final Countdown
// Contest: Codeforces - Codeforces Round 927 (Div. 3)
// URL: https://codeforces.com/contest/1932/problem/E
// Memory Limit: 512 MB
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
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    int rest = 0;
    stack<int> v;
    int ssums[n];
    ssums[n - 1] = (int)(s[n - 1] - '0');
    for (int i = n - 2; i >= 0; i--)
    {
        ssums[i] = ssums[i + 1] + (int)(s[i] - '0');
    }
    forn
    {
        int value = ssums[i];
        value += rest;
        v.push(value % 10);
        rest = value / 10;
    }
    v.push(rest);
    int leading_zero = 1;
    while (v.size() > 0)
    {
        if (v.top() == 0 && leading_zero)
        {
            v.pop();
        }
        else
        {
            leading_zero = 0;
            cout << v.top();
            v.pop();
        }
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
