// Problem: B. Cat, Fox and the Lonely Array
// Contest: Codeforces - Codeforces Round 945 (Div. 2)
// URL: https://codeforces.com/contest/1973/problem/B
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

int a[100000];
int n;

int simulate(int k)
{
    vector<vector<int>> table(20, vector<int>(n, 0));
    forn
    {
        for (int j = 0; j < 20; j++)
        {
            table[j][i] = (a[i] & (1 << j)) > 0;
        }
    }
    for (int i = 0; i < 20; i++)
    {
        int act = 0;
        for (int j = 0; j < k; j++)
        {
            act += table[i][j];
        }
        for (int j = 1; j <= n - k; j++)
        {
            int prev = act;
            int next = act - table[i][j - 1] + table[i][j + k - 1];
            if (prev > 0 && next == 0)
            {
                return 0;
            }
            if (prev == 0 && next > 0)
            {
                return 0;
            }
            act = next;
        }
    }
    return 1;
}

void Solve()
{
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    int st = 1;
    int ed = n;
    while (ed - st > 1)
    {
        int md = st + (ed - st) / 2;
        if (simulate(md))
        {
            ed = md;
        }
        else
        {
            st = md + 1;
        }
    }
    if (ed - 1 >= 1 && simulate(ed - 1))
    {
        ed--;
    }
    cout << ed << endl;
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