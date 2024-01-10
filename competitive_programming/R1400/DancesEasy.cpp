// Problem: G1. Dances (Easy version)
// Contest: Codeforces - Codeforces Round 905 (Div. 3)
// URL: https://codeforces.com/contest/1883/problem/G1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int removed = 0;
    int l_pointer = 0;
    forn
    {
        if (b[i] <= a[l_pointer])
        {
            removed++;
        }
        else
        {
            l_pointer++;
        }
    }
    cout << removed << endl;
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
