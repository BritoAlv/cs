// Problem: A. Log Chopping
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/problemset/problem/1672/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
    Math Proof: notice that every mov increments
    the number of logs, and the final number of logs
    is invariant.
*/

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int parity = n % 2;
    int sum = 0;
    while (n > 0)
    {
        int t;
        cin >> t;
        sum += t;
        n--;
    }

    cout << ((parity + (sum % 2)) == 1 ? "errorgorn" : "maomao90") << '\n';

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
