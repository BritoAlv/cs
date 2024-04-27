// Problem: A. Compare T-Shirt Sizes
// Contest: Codeforces - Codeforces Round 826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    string a, b;
    cin >> a >> b;
    char letter1 = a.back();
    char letter2 = b.back();
    if (letter1 != letter2)
    {
        if (letter1 == 'L')
        {
            cout << '>' << endl;
        }
        else if (letter2 == 'L')
        {
            cout << '<' << endl;
        }
        else if (letter1 == 'M')
        {
            cout << '>' << endl;
        }
        else
        {
            cout << '<' << endl;
        }
    }
    else
    {
        if (a.sz == b.sz)
        {
            cout << '=' << endl;
        }
        else if (letter1 == 'L')
        {
            if (a.sz > b.sz)
            {
                cout << '>' << endl;
            }
            else
            {
                cout << '<' << endl;
            }
        }
        else
        {
            if (a.sz > b.sz)
            {
                cout << '<' << endl;
            }
            else
            {
                cout << '>' << endl;
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
