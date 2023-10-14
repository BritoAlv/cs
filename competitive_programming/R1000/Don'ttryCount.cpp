// Problem: A. Don't Try to Count
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/0
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
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    string start = x;
    int op = 0;

    for (int i = 0; i < x.size(); i++)
    {
        bool works = true;
        for (int j = 0; j < s.size(); j++)
        {
            if (x[(i + j) % x.size()] != s[j])
            {
                works = false;
                break;
            }
        }
        if (works)
        {
            int min_len = i + s.size();
            int start_len = x.size();
            int op = 0;
            while (start_len < min_len)
            {
                op++;
                start_len *= 2;
            }
            cout << op << endl;
            return;
        }
    }
    cout << -1 << endl;
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
