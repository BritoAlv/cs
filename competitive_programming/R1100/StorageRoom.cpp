// Problem: B. StORage room
// Contest: Codeforces - Codeforces Round 912 (Div. 2)
// URL: https://codeforces.com/contest/1903/problem/B
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

using namespace std;

void Solve()
{
    int n, m;
    cin >> n;
    m = n;
    int a[n];
    vector<vector<int>> matrix;
    forn
    {
        matrix.pb(vector<int>(n));
        long long andd = (1 << 30) - 1;
        form
        {
            cin >> matrix[i][j];
            if (i != j)
            {
                andd &= matrix[i][j];
            }
        }
        a[i] = andd;
    }
    forn
    {
        form
        {
            if (i != j && ((a[i] | a[j]) != matrix[i][j]))
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    forn
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
