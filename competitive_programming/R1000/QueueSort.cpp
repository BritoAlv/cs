// Problem: E. Queue Sort
// Contest: Codeforces - Codeforces Round 909 (Div. 3)
// URL: https://codeforces.com/contest/1899/problem/E
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
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }

    int index_min = 0;
    int minn = a[0];

    forn
    {
        if (a[i] < minn)
        {
            minn = a[i];
            index_min = i;
        }
    }

    int sorted = 1;
    for (int i = index_min + 2; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            sorted = 0;
            break;
        }
    }
    if (sorted)
    {
        cout << index_min << endl;
    }
    else
    {
        cout << -1 << endl;
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
