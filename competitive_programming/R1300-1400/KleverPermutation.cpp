// Problem: E. Klever Permutation
// Contest: Codeforces - Codeforces Round 923 (Div. 3)
// URL: https://codeforces.com/contest/1927/problem/E
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

int validator(int p[], int n, int k)
{
    ull sums[n - k + 1];
    for (int i = 0; i < n - k + 1; i++)
    {
        sums[i] = 0;
        for (int j = i; j < i + k; j++)
        {
            sums[i] += p[j];
        }
    }
    sort(sums, sums + n - k + 1);
    return (sums[n - k] - sums[0] <= 1);
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans(n, -1);
    int low_num = 1;
    int big_num = n;
    int use_low = 1;
    for (int j = 0; j < k; j++)
    {
        for (int i = j; i < n; i += k)
        {
            if (use_low)
            {
                ans[i] = low_num;
                low_num++;
            }
            else
            {
                ans[i] = big_num;
                big_num--;
            }
        }
        use_low = !use_low;
    }
    forn
    {
        cout << ans[i] << wp;
    }
    cout << endl;
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
