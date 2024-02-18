// Problem: C. LR-remainders
// Contest: Codeforces - Codeforces Round 927 (Div. 3)
// URL: https://codeforces.com/contest/1932/problem/C
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

int n, m;
int a[200000];

void compute_product(int l, int r)
{
    int pr = 1;
    for (int i = l; i <= r; i++)
    {
        pr *= a[i];
        pr %= m;
    }
    cout << pr << wp;
}

void Solve()
{
    cin >> n >> m;
    forn
    {
        cin >> a[i];
    }
    int lpointer = 0;
    int rpointer = n - 1;
    string s;
    cin >> s;
    forn
    {
        if (s[i] == 'L')
        {
            lpointer++;
        }
        else
        {
            rpointer--;
        }
    }
    stack<int> results;
    int pr = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i != n - 1)
        {
            results.push(pr);
        }

        if (s[i] == 'L')
        {
            lpointer--;
            pr *= a[lpointer];
            pr %= m;
        }
        else
        {
            rpointer++;
            pr *= a[rpointer];
            pr %= m;
        }
    }
    results.push(pr);
    while (results.size() > 0)
    {
        cout << results.top() << wp;
        results.pop();
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
