// Problem: A. Rectangle Cutting
// Contest: Codeforces - Codeforces Round 924 (Div. 2)
// URL: https://codeforces.com/contest/1928/problem/A
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0)
    {
        int new_a = a / 2;
        int new_b = 2 * b;
        if (new_a != b || new_b != a)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    if (b % 2 == 0)
    {
        int new_b = b / 2;
        int new_a = 2 * a;
        if (new_b != a || new_a != b)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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
