// Problem: C. Jellyfish and Green Apple
// Contest: Codeforces - Codeforces Round 901 (Div. 2)
// URL: https://codeforces.com/contest/1875/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

long long mcd(long long a, long long b)
{
    if (a > b)
    {
        return mcd(b, a);
    }
    else if (a == b)
    {
        return a;
    }
    else
    {
        // a < b
        if (b % a == 0)
        {
            return a;
        }
        else
        {
            return mcd(b % a, a);
        }
    }
}

void Solve()
{
    long long a, b;
    cin >> a >> b;
    long long mcdd = mcd(a, b);
    long long c = b / mcdd;
    bool works = true;
    while (c >= 2)
    {
        if (c % 2 != 0)
        {
            works = false;
            break;
        }
        c = c / 2;
    }
    if (!works)
    {
        cout << -1 << endl;
    }
    else
    {
        long long op = 0;
        while (a % b != 0)
        {
            a = a % b;
            op += a;
            a *= 2;
        }
        cout << op << endl;
    }
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
