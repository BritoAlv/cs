// Problem: A. Tenzing and Tsondu
// Contest: Codeforces - CodeTON Round 5 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1842/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n, m;
    cin >> n >> m;
    long long sum_n = 0;
    long long sum_m = 0;
    forn
    {
        int a;
        cin >> a;
        sum_n += a;
    }
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        sum_m += b;
    }

    if (sum_n > sum_m)
    {
        cout << "Tsondu" << endl;
    }
    else if (sum_m > sum_n)
    {
        cout << "Tenzing" << endl;
    }
    else
    {
        cout << "Draw" << endl;
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
