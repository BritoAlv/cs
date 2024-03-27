// Problem: L. Controllers
// Contest: Codeforces - SWERC 2022-2023 - Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1776/L
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n;
    cin >> n;
    int cantp = 0;
    forn
    {
        char t;
        cin >> t;
        cantp += (t == '+');
    }
    int q;
    cin >> q;
    while (q > 0)
    {
        q--;
        long long ai, bj;
        cin >> ai >> bj;
        if (ai == bj)
        {
            cout << (2 * cantp == n ? "YES" : "NO") << endl;
            continue;
        }
        long long v = bj * (n - 2 * cantp);
        if (v % (ai - bj) == 0)
        {
            long long dif = v / (ai - bj);
            if (dif >= 0)
            {
                cout << (dif <= cantp ? "YES" : "NO") << endl;
            }
            else
            {
                cout << (-dif <= n - cantp ? "YES" : "NO") << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
