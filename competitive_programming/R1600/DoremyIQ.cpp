// Problem: C. Doremy's IQ
// Contest: Codeforces - Codeforces Round 808 (Div. 2)
// URL: https://codeforces.com/contest/1708/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int n, q;
    cin >> n >> q;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> positions(n);
    int to_choose = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] <= to_choose)
        {
            positions[i] = 1;
        }
        else
        {
            if (to_choose < q)
            {
                to_choose++;
                positions[i] = 1;
            }
        }
    }
    forn
    {
        cout << positions[i];
    }
    cout << endl;
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
