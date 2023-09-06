// Problem: B. MKnez's ConstructiveForces Task
// Contest: Codeforces - Hello 2023
// URL: https://codeforces.com/problemset/problem/1779/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: did a stupid thing in this one, use wrong test_cases to spoil answer, that's not good

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << "NO" << '\n';
    }
    else if (n % 2 == 1)
    {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++)
        {
            cout << ((i % 2 == 0) ? (n / 2 - 1) : -(n / 2)) << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++)
        {
            cout << pow(-1, i) << " ";
        }
        cout << '\n';
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
