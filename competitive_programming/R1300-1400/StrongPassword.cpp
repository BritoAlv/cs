// Problem: C. Strong Password
// Contest: Codeforces - Educational Codeforces Round 151 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1845/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

int find_first(int start_pos, int h, string &S)
{
    for (int i = start_pos; i < S.size(); i++)
    {
        if ((S[i] - '0') == h)
        {
            return i;
        }
    }
    return -1;
}

void Solve()
{
    string S;
    int m;
    string l;
    string r;
    cin >> S >> m >> l >> r;
    int before = -1;
    for (int i = 0; i < m; i++)
    {
        int first = -1;
        for (int h = l[i] - '0'; h <= r[i] - '0'; h++)
        {
            int x = find_first(before + 1, h, S);
            if (x == -1)
            {
                cout << "YES" << endl;
                return;
            }
            else
            {
                first = max(x, first);
            }
        }
        before = first;
    }
    cout << "NO" << endl;
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
