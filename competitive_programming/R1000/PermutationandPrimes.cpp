// Problem: B. Permutations & Primes
// Contest: Codeforces - Codeforces Round 884 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1844/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: put 2 and 3 in borders, 1 in the middle.
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
    int n;
    cin >> n;
    if (n <= 2)
    {
        forn
        {
            cout << i + 1 << wp;
        }
        cout << endl;
    }
    else if (n == 3)
    {
        cout << "3 1 2" << endl;
    }
    else
    {
        int it = 4;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                cout << 2 << wp;
            }
            else if (i == n / 2)
            {
                cout << 1 << wp;
            }
            else if (i == n - 1)
            {
                cout << 3 << wp;
            }
            else
            {
                cout << it << wp;
                it++;
            }
        }
        cout << endl;
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