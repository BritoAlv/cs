// Problem: D. Mathematical Problem
// Contest: Codeforces - Codeforces Round 954 (Div. 3)
// URL: https://codeforces.com/contest/1986/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    int n;
    cin >> n;
    vector<char> s(n);
    forn
    {
        cin >> s[i];
    }
    long long best = 1e18;
    vector<int> ss(n);
    forn
    {
        ss[i] = s[i] - '0';
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> sss(n - 1);
        int index = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                sss[index - 1] *= 10;
                sss[index - 1] += ss[j];
            }
            else
            {
                sss[index] = ss[j];
                index++;
            }
        }
        long long sum = 0;
        sum = sss[0];
        for (int j = 1; j < n - 1; j++)
        {
            if (sss[j] <= 1 || sum <= 1)
            {
                sum = sss[j] * sum;
            }
            else
            {
                sum += sss[j];
            }
        }
        best = min(sum, best);
    }
    cout << best << endl;
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