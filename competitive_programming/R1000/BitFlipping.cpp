// Problem: B. Bit Flipping
// Contest: Codeforces - Codeforces Round 782 (Div. 2)
// URL: https://codeforces.com/contest/1659/problem/B
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
    vector<int> S(n);
    forn
    {
        char t;
        cin >> t;
        if (t == '1')
        {
            S[i] = 1;
        }
        else
        {
            S[i] = 0;
        }
    }

    vector<int> a(n);
    int capacity = k;
    int choose = k % 2;
    forn
    {
        if (S[i] == choose && capacity > 0)
        {
            a[i]++;
            capacity--;
        }
    }
    if (capacity > 0)
    {
        a[n - 1] += capacity;
    }
    forn
    {
        int invert = (k % 2 + a[i] % 2) % 2;
        if (invert > 0)
        {
            cout << !S[i];
        }
        else
        {
            cout << S[i];
        }
    }
    cout << endl;
    forn
    {
        cout << a[i] << wp;
    }
    cout << endl;
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
