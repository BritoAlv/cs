// Problem: C. Particles
// Contest: Codeforces - Codeforces Round 884 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1844/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void print_vector(vector<int> &a)
{
    for (auto x : a)
    {
        cout << x << wp;
    }
    cout << endl;
}

void print_yes(int a)
{
    if (a != 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

void Solve()
{
    int n;
    cin >> n;
    long long odd = 0;
    long long even = 0;
    long long min = -(1e9 + 1);
    bool found_positive = 0;
    forn
    {
        int a;
        cin >> a;
        if (a >= 0)
        {
            found_positive = 1;
        }
        if (a < 0 && a > min)
        {
            min = a;
        }
        if (a > 0 && i % 2 == 0)
        {
            odd += a;
        }
        if (a > 0 && i % 2 == 1)
        {
            even += a;
        }
    }
    if (found_positive)
    {
        cout << max(even, odd) << endl;
    }
    else
    {
        cout << min << endl;
    }

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
