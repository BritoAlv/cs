// Problem: E. Find the Car
// Contest: Codeforces - Codeforces Round 944 (Div. 4)
// URL: https://codeforces.com/contest/1971/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<ull> a(k + 1, 0);
    vector<ull> b(k + 1, 0);
    fork
    {
        cin >> a[i + 1];
    }
    fork
    {
        cin >> b[i + 1];
    }
    while (q > 0)
    {
        int d;
        cin >> d;
        int st = 0;
        int pt = k;
        while (pt - st > 1)
        {
            int md = st + (pt - st) / 2;
            if (d <= a[md])
            {
                pt = md;
            }
            else
            {
                st = md + 1;
            }
        }
        if (pt > 0 && d <= a[pt - 1])
        {
            pt--;
        }
        ull time = 0;
        if (pt > 0)
        {
            time += b[pt - 1];
            time += (d - a[pt - 1]) * (b[pt] - b[pt - 1]) / (a[pt] - a[pt - 1]);
        }
        cout << time << wp;
        q--;
    }
    cout << endl;
    return;
}

void Solve()
{
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
        BruteSolve();
    }
    return 0;
}
