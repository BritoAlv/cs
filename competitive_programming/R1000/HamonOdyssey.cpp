// Problem: B. Hamon Odyssey
// Contest: Codeforces - Codeforces Round 882 (Div. 2)
// URL: https://codeforces.com/contest/1847/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: A and B <= min(A,B)
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
    int divs = 0;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int start_and = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            divs++;
            start_and = (i == n - 1 ? start_and : a[i + 1]);
        }
        else if ((a[i] & start_and) == 0)
        {
            divs++;
            start_and = (i == n - 1 ? start_and : a[i + 1]);
        }
        else
        {
            start_and = a[i] & start_and;
        }
    }
    cout << max(1, divs) << endl;
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
