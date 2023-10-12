// Problem: E. Exchange
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules,
// Preferably Teams) URL: https://codeforces.com/problemset/problem/1765/E Memory Limit: 512 MB Time Limit: 2000 ms Math
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
    int n, a, b;
    cin >> n >> a >> b;
    if (b >= a)
    {
        cout << n / a + (n % a != 0) << endl;
    }
    else
    {
        cout << 1 << endl;
    }
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
