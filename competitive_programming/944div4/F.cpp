// Problem: F. Circle Perimeter
// Contest: Codeforces - Codeforces Round 944 (Div. 4)
// URL: https://codeforces.com/contest/1971/problem/F
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

void Solve()
{
    long long r;
    cin >> r;
    ull ans = 0;
    for (long long x = 0; x <= r; x++)
    {
        long long st = 0;
        long long ed = r;
        while (ed - st > 1)
        {
            long long md = st + (ed - st) / 2;
            if (x * x + md * md >= r * r)
            {
                ed = md;
            }
            else
            {
                st = md + 1;
            }
        }
        while (x * x + (ed - 1) * (ed - 1) >= r * r && ed - 1 >= 0)
        {
            ed--;
        }
        if (x * x < (r + 1) * (r + 1))
        {
            long long stt = 0;
            long long edd = r + 1;
            while (edd - stt > 1)
            {
                long long md = stt + (edd - stt) / 2;
                if (x * x + md * md < (r + 1) * (r + 1))
                {
                    stt = md;
                }
                else
                {
                    edd = md - 1;
                }
            }
            while (x * x + (stt + 1) * (stt + 1) < (r + 1) * (r + 1))
            {
                stt++;
            }
            if (ed <= stt)
            {
                ans += 4 * (stt - ed + 1);
            }
        }
    }
    cout << ans - 4 << endl;
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
