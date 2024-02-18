// Problem: A. Thorns and Coins
// Contest: Codeforces - Codeforces Round 927 (Div. 3)
// URL: https://codeforces.com/contest/1932/problem/A
// Memory Limit: 512 MB
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
    int n;
    cin >> n;
    vector<char> a(n);
    forn
    {
        cin >> a[i];
    }

    int n_coins = 0;
    forn
    {
        if (a[i] == '@')
        {
            n_coins++;
        }
        else if (a[i] == '*' && (i < n - 1 && a[i + 1] == '*'))
        {
            cout << n_coins << endl;
            return;
        }
    }
    cout << n_coins << endl;
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
