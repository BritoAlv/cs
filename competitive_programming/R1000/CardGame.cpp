// Problem: C. Card Game
// Contest: Codeforces - Codeforces Round 899 (Div. 2)
// URL: https://codeforces.com/contest/1882/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    vector<int> a;
    forn
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    long long sum = 0;
    int parity = 1;
    int end = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (parity > 0 && a[i] > 0)
        {
            for (int j = n - 1; j >= i; j--)
            {
                if (a[j] > 0)
                {
                    sum += a[j];
                }
            }
            end = i - 1;
            break;
        }
        parity = (parity + 1) % 2;
    }
    if (end >= 1)
    {
        int start = 0;
        a[1] = max(0, a[1] + a[0]);
        for (int i = 1; i <= end; i += 2)
        {
            sum += max(0, a[i]);
        }
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
