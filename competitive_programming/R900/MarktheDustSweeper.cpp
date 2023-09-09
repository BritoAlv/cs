// Problem: B. Mark the Dust Sweeper
// Contest: Codeforces - Codeforces Round 807 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1705/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Math Proof: do exactly one operation to every zero in a wrong position.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int d[n];
    int index = -1;
    long long sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> d[i];
        if (d[i] > 0)
        {
            index = i;
        }
        if (d[i] == 0 && i > index && index >= 0)
        {
            sum++;
        }
        sum += d[i];
    }
    cin >> d[n - 1];
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
