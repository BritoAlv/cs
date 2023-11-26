// Problem: B. Multiply by 2, divide by 6
// Contest: Codeforces - Codeforces Round 653 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1374/B
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
#define vi vector<int>

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
    int ops = 0;
    while (n > 1)
    {
        if (n % 6 == 0)
        {
            n = n / 6;
            ops++;
        }
        else if ((2 * n) % 6 == 0)
        {
            n *= 2;
            n = n / 6;
            ops += 2;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ops << endl;
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
