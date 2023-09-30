// Problem: B. Jellyfish and Game
// Contest: Codeforces - Codeforces Round 901 (Div. 2)
// URL: https://codeforces.com/contest/1875/problem/B
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
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    int b[m];
    forn
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int ops = 1;
    while (ops <= k && ops <= 200)
    {
        if (ops % 2 == 1)
        {
            if (a[0] < b[m - 1])
            {
                int c = a[0];
                a[0] = b[m - 1];
                b[m - 1] = c;
                sort(a, a + n);
                sort(b, b + m);
            }
        }
        else
        {
            if (b[0] < a[n - 1])
            {
                int c = b[0];
                b[0] = a[n - 1];
                a[n - 1] = c;
                sort(a, a + n);
                sort(b, b + m);
            }
        }
        ops++;
    }
    if (ops == 201 && k % 2 == 1)
    {

        if (ops % 2 == 1)
        {
            if (a[0] < b[m - 1])
            {
                int c = a[0];
                a[0] = b[m - 1];
                b[m - 1] = c;
                sort(a, a + n);
                sort(b, b + m);
            }
        }
        else
        {
            if (b[0] < a[n - 1])
            {
                int c = b[0];
                b[0] = a[n - 1];
                a[n - 1] = c;
                sort(a, a + n);
                sort(b, b + m);
            }
        }
        ops++;
    }

    long long sum = 0;
    for (auto x : a)
    {
        sum += x;
    }
    cout << sum << endl;
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