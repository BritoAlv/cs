// Problem: A. Rating Increase
// Contest: Codeforces - Educational Codeforces Round 160 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1913/problem/A
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
#define ull unsigned long long
using namespace std;

void Solve()
{
    string s;
    cin >> s;
    queue<char> one;
    one.push(s[0]);
    queue<char> two;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            one.push(s[i]);
        }
        else
        {
            for (int j = i; j < s.size(); j++)
            {
                two.push(s[j]);
            }
            break;
        }
    }
    int n1 = 0;
    int n2 = 0;
    while (one.size() > 0)
    {
        n1 = (one.front() - '0') + 10 * n1;
        one.pop();
    }
    while (two.size() > 0)
    {
        n2 = (two.front() - '0') + 10 * n2;
        two.pop();
    }
    if (n1 < n2)
    {
        cout << n1 << wp << n2 << endl;
    }
    else
    {
        cout << -1 << endl;
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
