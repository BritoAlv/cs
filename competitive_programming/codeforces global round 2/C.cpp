// Problem: C. Ramesses and Corner Inversion
// Contest: Codeforces - Codeforces Global Round 2
// URL: https://codeforces.com/contest/1119/problem/C
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    forn
    {
        form
        {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> B(n, vector<int>(m));
    forn
    {
        form
        {
            cin >> B[i][j];
        }
    }
    int flag1 = 0;
    int flag2 = 0;
    forn
    {
        int count = 0;
        form
        {
            if (A[i][j] != B[i][j])
            {
                count++;
            }
        }
        if (count % 2)
        {
            flag1 = 1;
        }
    }
    form
    {
        int count = 0;
        forn
        {
            if (A[i][j] != B[i][j])
            {
                count++;
            }
        }
        if (count % 2)
        {
            flag2 = 1;
        }
    }
    cout << (flag1 || flag2 ? "No" : "Yes") << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
