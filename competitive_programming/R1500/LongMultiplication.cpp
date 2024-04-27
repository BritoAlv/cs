// Problem: C. Long Multiplication
// Contest: Codeforces - Educational Codeforces Round 164 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1954/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int cv(char i)
{
    return (int)(i - '0');
}

void Solve()
{
    string a;
    string b;
    cin >> a >> b;
    int i = 0;
    bool to_b = false;
    for (; i < a.sz; i++)
    {
        if (a[i] != b[i])
        {
            if (cv(a[i]) > cv(b[i]))
            {
                to_b = true;
            }
            break;
        }
    }
    for (int j = i + 1; j < a.sz; j++)
    {
        if (cv(a[j]) > cv(b[j]) && to_b)
        {
            char temp = a[j];
            a[j] = b[j];
            b[j] = temp;
        }
        if (cv(b[j]) > cv(a[j]) && !to_b)
        {
            char temp = a[j];
            a[j] = b[j];
            b[j] = temp;
        }
    }
    cout << a << endl;
    cout << b << endl;
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
