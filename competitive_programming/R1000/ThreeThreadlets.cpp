// Problem: B. Three Threadlets
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    int n = 3;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int min = a[0];
    if (a[1] < min)
    {
        min = a[1];
    }
    if (a[2] < min)
    {
        min = a[2];
    }
    int count[4];
    for (int i = 0; i < 4; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == min)
        {
            count[0]++;
        }
        if (a[i] == 2 * min)
        {
            count[1]++;
        }
        if (a[i] == 3 * min)
        {
            count[2]++;
        }
        if (a[i] == 4 * min)
        {
            count[3]++;
        }
    }
    if (count[0] == 3)
    {
        cout << "YES" << endl;
    }

    else if (count[0] == 2 && count[1] == 1)
    {
        cout << "YES" << endl;
    }
    else if (count[0] == 2 && count[3] == 1)
    {
        cout << "YES" << endl;
    }
    else if (count[1] == 2 && count[0] == 1)
    {
        cout << "YES" << endl;
    }

    else if (count[0] == 2 && count[2] == 1)
    {
        cout << "YES" << endl;
    }

    else if (count[0] == 1 && count[1] == 1 && count[2] == 1)
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
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
