// Problem: A. Secret Sport
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/A
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
    string s;
    cin >> s;
    cout << s[n - 1] << endl;
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
