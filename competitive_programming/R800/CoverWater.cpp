// Problem: A. Cover in Water
// Contest: Codeforces - Codeforces Round 911 (Div. 2)
// URL: https://codeforces.com/contest/1900/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int i = 0; i < m; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int max_len_dot = 0;
    int dot_count = 0;
    forn
    {
        char t;
        cin >> t;
        if (t == '.')
        {
            max_len_dot++;
            dot_count++;
        }
        else
        {
            if (max_len_dot < 3)
            {
                max_len_dot = 0;
            }
            else
            {
                max_len_dot = 3;
            }
        }
    }
    if (max_len_dot < 3)
    {
        cout << dot_count << endl;
    }
    else
    {
        cout << 2 << endl;
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
