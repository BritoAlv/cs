// Problem: C. OKEA
// Contest: Codeforces - Codeforces Round 770 (Div. 2)
// URL: https://codeforces.com/contest/1634/problem/C
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

void Solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << i << endl;
        }
    }
    else if (n % 2 == 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        int first_even = 2;
        int first_odd = 1;
        int count = 0;
        while (first_even <= n * k)
        {
            cout << first_even << wp;
            first_even += 2;
            count++;
            if (count == k)
            {
                cout << endl;
                count = 0;
            }
        }
        while (first_odd <= n * k)
        {
            cout << first_odd << wp;
            first_odd += 2;
            count++;
            if (count == k)
            {
                cout << endl;
                count = 0;
            }
        }
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
