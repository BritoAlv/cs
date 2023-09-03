// Problem: B. Mex Master
// Contest: Codeforces - Codeforces Round 858 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1806/B
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Math Proof:

#include <bits/stdc++.h>

using namespace std;

int test_cases;

int Solve()
{
    int n;
    cin >> n;

    int smallest = 200001;
    int greatest = 0;
    int cant_zeros = 0;

    int m = n - 1;
    while (m >= 0)
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            cant_zeros++;
        }
        else
        {
            smallest = min(smallest, t);
            greatest = max(smallest, t);
        }
        m--;
    }

    if (cant_zeros == n)
    {
        return 1;
    }
    else if (cant_zeros == 0)
    {
        return 0;
    }

    else if ((cant_zeros - (n % 2)) <= n - cant_zeros)
    {
        return 0;
    }

    else
    {
        if (smallest >= 2 || greatest >= 2)
        {
            return 1;
        }
        return 2;
    }
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        cout << Solve() << '\n';
        test_cases--;
    }
    return 0;
}
