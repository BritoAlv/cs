// Problem: B. Getting Points
// Contest: Codeforces - Educational Codeforces Round 159 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1902/problem/B
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

using namespace std;

void Solve()
{
    long long n, P, c, p;
    cin >> n >> P >> c >> p;
    long long type1 = 2 * p + c;
    long long type2 = p + c;
    long long type3 = c;
    long long especial_days = n / 7 + (n % 7 != 0);
    if ((type1 * (especial_days / 2)) >= P)
    {
        cout << n - (P / (type1) + (P % type1 != 0)) << endl;
    }
    else
    {
        long long ans = (especial_days / 2);
        P -= type1 * (especial_days / 2);
        especial_days -= 2 * (especial_days / 2);
        if (type2 * especial_days >= P)
        {
            cout << n - (ans + (P / (type2) + (P % type2 != 0))) << endl;
        }
        else
        {
            ans += especial_days;
            P -= type2 * especial_days;
            cout << n - (ans + (P / (type3) + (P % type3 != 0))) << endl;
        }
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
