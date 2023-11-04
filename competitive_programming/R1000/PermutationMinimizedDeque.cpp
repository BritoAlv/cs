// Problem: E1. Permutation Minimization by Deque
// Contest: Codeforces - Codeforces Round 744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/E1
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

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int a_index = 0;
    deque<int> d;
    while (a[a_index] != 1)
    {
        if (d.size() == 0 || a[a_index] < d.front())
        {
            d.push_front(a[a_index]);
        }
        else
        {
            d.push_back(a[a_index]);
        }
        a_index++;
    }
    cout << 1 << wp;
    for (auto x : d)
    {
        cout << x << wp;
    }
    for (int i = a_index + 1; i < n; i++)
    {
        cout << a[i] << wp;
    }
    cout << endl;
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
