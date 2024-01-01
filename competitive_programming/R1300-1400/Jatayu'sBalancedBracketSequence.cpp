// Problem: C. Jatayu's Balanced Bracket Sequence
// Contest: Codeforces - Codeforces Round 819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.com/problemset/problem/1726/C
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
#define pb push_back
#define ull unsigned long long
using namespace std;

char A[200000];
int pos[200000];

int linear_solve(int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    else if (end == start + 1)
    {
        return 1;
    }
    int ans = 1;
    int b = start;
    int e = pos[b];
    while (true)
    {
        ans += linear_solve(b + 1, e - 1);
        b = e + 1;
        if (e == end)
        {
            break;
        }
        else
        {
            e = pos[b];
        }
    }
    return ans;
}

void Solve()
{
    int n;
    cin >> n;
    stack<int> opens;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> A[i];
        if (A[i] == '(')
        {
            opens.push(i);
        }
        else
        {
            pos[opens.top()] = i;
            opens.pop();
        }
    }
    cout << linear_solve(0, 2 * n - 1) << endl;
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
