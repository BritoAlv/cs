// Problem: A. AvtoBus
// Contest: Codeforces - Codeforces Round 791 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1679/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: this is the type of the problem where I got two
// WA, even when I can test small cases to ensure that what
// I wrote is not wrong, I'm' stupid.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    long long n;
    cin >> n;
    if (n % 2 == 1 || n == 2)
    {
        cout << -1 << endl;
    }
    else
    {
        if ((n / 2) % 3 == 0)
        {
            cout << n / 6 << ' ';
        }
        else if ((n / 2) % 3 == 1)
        {
            cout << 2 + (n / 2 - 4) / 3 << ' ';
        }
        else
        {
            cout << 1 + (n / 2 - 2) / 3 << ' ';
        }

        if ((n / 2) % 2 == 0)
        {
            cout << n / 4 << endl;
        }
        else
        {
            cout << 1 + (n / 2 - 3) / 2 << endl;
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
