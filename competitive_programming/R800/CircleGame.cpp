// Problem: B. Circle Game
// Contest: Codeforces - Codeforces Round 801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/B
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
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }

    if (n % 2)
    {
        cout << "Mike" << endl;
    }
    else
    {
        int index_min = 0;
        int min_v = a[0];
        forn
        {
            if (a[i] < min_v)
            {
                index_min = i;
                min_v = a[i];
            }
        }
        if (index_min % 2 == 1)
        {
            cout << "Mike" << endl;
        }
        else
        {
            cout << "Joe" << endl;
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
