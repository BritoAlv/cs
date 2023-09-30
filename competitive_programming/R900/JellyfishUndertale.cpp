// Problem: A. Jellyfish and Undertale
// Contest: Codeforces - Codeforces Round 901 (Div. 2)
// URL: https://codeforces.com/contest/1875/problem/0
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
    int a, b, n;
    cin >> a >> b >> n;
    int t[n];
    forn
    {
        cin >> t[i];
    }

    long long time = b - 1;
    int actual_time = 1;
    forn
    {
        actual_time = min(1 + t[i], a);
        time += (actual_time - 1);
    }
    cout << time + 1 << endl;
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
