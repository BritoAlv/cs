// Problem: E1. Rudolf and Snowflakes (simple version)
// Contest: Codeforces - Codeforces Round 883 (Div. 3)
// URL: https://codeforces.com/contest/1846/problem/E1
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

set<int> valid_ones;

void init()
{
    for (int k = 2; k < 1000; k++)
    {
        int pow = 1;
        int sum = 1;
        for (int exp = 1; exp <= 100; exp++)
        {
            pow *= k;
            sum += pow;
            if (sum > 1e6)
            {
                break;
            }
            if (exp >= 2)
            {
                valid_ones.insert(sum);
            }
        }
    }
}

void Solve()
{
    int n;
    cin >> n;
    if (valid_ones.find(n) != valid_ones.end())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}

int main()
{
    init();
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
