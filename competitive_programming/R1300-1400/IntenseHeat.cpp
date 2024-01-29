// Problem: C. Intense Heat
// Contest: Codeforces - Codeforces Round 494 (Div. 3)
// URL: https://codeforces.com/contest/1003/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
    int n, k;
    cin >> n >> k;
    ull psum[n];
    forn
    {
        psum[i] = 0;
    }
    forn
    {
        int c;
        cin >> c;
        psum[i] = c;
        if (i > 0)
        {
            psum[i] += psum[i - 1];
        }
    }
    pair<ull, int> maxx = {-1, -1};
    forn
    {
        for (int j = i; j < n; j++)
        {
            if (j - i + 1 >= k)
            {
                ull sum = psum[j] - (i > 0 ? psum[i - 1] : 0);
                if (maxx.first == -1 || maxx.first * (j - i + 1) < sum * maxx.second)
                {
                    maxx = {sum, j - i + 1};
                }
            }
        }
    }
    double av = maxx.first;
    av /= maxx.second;
    cout << setprecision(15) << av << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
