// Problem: Make it White
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/1927/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<char> a(n);
    int low_b = -1;
    int great_b = -1;
    forn
    {
        cin >> a[i];
        if (a[i] == 'B' && low_b == -1)
        {
            low_b = i;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 'B' && great_b == -1)
        {
            great_b = i;
        }
    }
    cout << great_b - low_b + 1 << endl;
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
