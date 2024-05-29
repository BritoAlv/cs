// Problem: B. Binary Colouring
// Contest: Codeforces - Codeforces Round 948 (Div. 2)
// URL: https://codeforces.com/contest/1977/problem/B
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
    int x;
    cin >> x;
    vector<int> binary;
    vector<int> repr;
    while (x > 0)
    {
        binary.pb(x % 2);
        repr.pb(x % 2);
        x = x / 2;
    }
    while (repr.sz < 32)
    {
        repr.pb(0);
    }
    for (int i = 0; i < repr.sz; i++)
    {
        if (repr[i] == 1)
        {
            int ed = i;
            while (ed + 1 < repr.sz && repr[ed + 1] == 1)
            {
                ed++;
            }
            if (ed > i)
            {
                repr[i] = -1;
                for (int j = i + 1; j <= ed; j++)
                {
                    repr[j] = 0;
                }
                repr[ed + 1] = 1;
                i = ed;
            }
        }
    }
    cout << repr.sz << endl;
    for (auto x : repr)
    {
        cout << x << wp;
    }
    cout << endl;
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
