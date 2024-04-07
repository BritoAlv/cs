// Problem: C. Bitwise Operation Wizard
// Contest: Codeforces - Codeforces Round 930 (Div. 2)
// URL: https://codeforces.com/contest/1937/problem/C
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
    int n;
    cin >> n;
    int pos_m = 0;
    // find (n-1)
    for (int i = 1; i < n; i++)
    {
        cout << '?' << wp << pos_m << wp << pos_m << wp << i << wp << i << endl;
        cout.flush();
        char t;
        cin >> t;
        if (t == '<')
        {
            pos_m = i;
        }
    }
    int pos_n = 0;
    vector<int> equals{0};
    for (int i = 1; i < n; i++)
    {
        cout << '?' << wp << pos_m << wp << pos_n << wp << pos_m << wp << i << endl;
        cout.flush();
        char t;
        cin >> t;
        if (t == '<')
        {
            pos_n = i;
            equals = {pos_n};
        }
        else if (t == '=')
        {
            equals.pb(i);
        }
    }
    int pos_min = equals[0];
    for (int i = 1; i < equals.size(); i++)
    {
        cout << '?' << wp << pos_min << wp << pos_min << wp << equals[i] << wp << equals[i] << endl;
        cout.flush();
        char t;
        cin >> t;
        if (t == '>')
        {
            pos_min = equals[i];
        }
    }
    cout << '!' << wp << pos_m << wp << pos_min << endl;
    cout.flush();
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