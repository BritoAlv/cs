// Problem: C. Find a Mine
// Contest: Codeforces - Codeforces Round 931 (Div. 2)
// URL: https://codeforces.com/contest/1934/problem/C
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

int d(pi A, pi B)
{
    return abs(A.first - B.first) + abs(A.second - B.second);
}

int query(int a, int b)
{
    cout << "?" << wp << a << wp << b << endl;
    cout.flush();
    int d;
    cin >> d;
    return d;
}

void ans(int a, int b)
{
    cout << "!" << wp << a << wp << b << endl;
    cout.flush();
    return;
}

int n, m;

int inside_board(int a, int b)
{
    return a >= 0 && b >= 0 && a < n && b < n;
}

void Solve()
{
    cin >> n >> m;
    int d1 = query(1, 1);
    int d2 = query(n, m);
    int d3 = query(1, m);

    int y1 = (d1 - d3 + m + 1);
    if (y1 % 2 == 0)
    {
        y1 /= 2;
        int x1 = d1 - (y1 - 1) + 1;
        if (inside_board(x1, y1))
        {
            int d4 = query(x1, y1);
            if (d4 == 0)
            {
                ans(x1, y1);
            }
            else
            {
                int x2 = (n - d2 + d3 + 1);
                assert(x2 % 2 == 0);
                x2 /= 2;
                int y2 = (x2 - 1) - d3 + m;
                ans(x2, y2);
            }
            return;
        }
    }

    int x2 = (n - d2 + d3 + 1);
    assert(x2 % 2 == 0);
    x2 /= 2;
    int y2 = (x2 - 1) - d3 + m;
    int d4 = query(x2, y2);
    if (d4 == 0)
    {
        ans(x2, y2);
    }
    else
    {
        int y1 = (d1 - d3 + m + 1);
        assert(y1 % 2 == 0);
        y1 /= 2;
        int x1 = d1 - (y1 - 1) + 1;
        ans(x1, y1);
    }
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