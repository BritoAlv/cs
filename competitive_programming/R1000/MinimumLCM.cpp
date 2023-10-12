// Problem: M. Minimum LCM
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules,
// Preferably Teams) URL: https://codeforces.com/contest/1765/problem/M Memory Limit: 512 MB Time Limit: 2000 ms Math
// Proof:
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
    for (int i = 2; i <= sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            cout << n / i << wp << n - n / i << endl;
            return;
        }
    }
    cout << 1 << wp << (n - 1) << endl;
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