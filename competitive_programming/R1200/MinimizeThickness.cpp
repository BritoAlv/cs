// Problem: C. Minimize the Thickness
// Contest: Codeforces - Codeforces Round 826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/C
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn
    {
        cin >> a[i];
    }
    int ans = n;
    forn
    {
        ull ppsum = 0;
        set<int> l;
        l.insert(i + 1);
        int flag = 1;
        for (int j = 0; j <= i; j++)
        {
            ppsum += a[j];
        }
        for (int j = i + 1; j < n; j++)
        {
            ull seg_sum = a[j];
            int start = j;
            int end = j;
            while (end + 1 < n && seg_sum + a[end + 1] <= ppsum)
            {
                seg_sum += a[end + 1];
                end++;
            }
            if (seg_sum == ppsum)
            {
                l.insert(end - start + 1);
                j = end;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            ans = min(ans, *l.rbegin());
        }
    }
    cout << ans << endl;
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
