// Problem: B. Minimize Permutation Subarrays
// Contest: Codeforces - Codeforces Round 877 (Div. 2)
// URL: https://codeforces.com/contest/1838/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int one_pos;
    int two_pos;
    int n_pos;
    forn
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            one_pos = i + 1;
        }
        if (a == 2)
        {
            two_pos = i + 1;
        }
        if (a == n)
        {
            n_pos = i + 1;
        }
    }
    if (one_pos < two_pos)
    {
        if (n_pos > two_pos)
        {
            cout << n_pos << wp << two_pos << endl;
        }
        else if (n_pos < one_pos)
        {
            cout << n_pos << wp << one_pos << endl;
        }
        else
        {
            cout << n_pos << wp << n_pos << endl;
        }
    }
    else
    {
        if (n_pos < two_pos)
        {
            cout << n_pos << wp << two_pos << endl;
        }
        else if (n_pos > one_pos)
        {
            cout << n_pos << wp << one_pos << endl;
        }
        else
        {
            cout << n_pos << wp << n_pos << endl;
        }
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
