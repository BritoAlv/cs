// Problem: C. Closest Cities
// Contest: Codeforces - Educational Codeforces Round 161 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1922/problem/C
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

void Solve()
{
    int n;
    cin >> n;
    ull A[n];
    vector<int> marked(n, 0);
    forn
    {
        cin >> A[i];
    }
    marked[0] = 1; // mark means I can go to right.
    marked[n - 1] = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (A[i] - A[i - 1] > A[i + 1] - A[i])
        {
            marked[i] = 1;
        }
        else
        {
            marked[i] = 0;
        }
    }
    ull L[n];
    L[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        if (marked[i - 1])
        {
            L[i] = L[i - 1] + 1;
        }
        else
        {
            L[i] = L[i - 1] + (A[i] - A[i - 1]);
        }
    }
    ull R[n];
    R[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (!marked[i + 1])
        {
            R[i] = R[i + 1] + 1;
        }
        else
        {
            R[i] = R[i + 1] + (A[i + 1] - A[i]);
        }
    }
    int m;
    cin >> m;
    form
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ull distance = 0;
        if (a < b)
        {
            distance = L[b] - L[a];
        }
        else
        {
            distance = R[b] - R[a];
        }
        cout << distance << endl;
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
