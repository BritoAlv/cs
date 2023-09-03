// Problem: D. Odd Queries
// Contest: Codeforces - Codeforces Round 859 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1807/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: line 46 is interesting

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;

    int q;
    cin >> q;

    int odds = 0;
    int even = 0;
    vector<int> odds_count;
    vector<int> even_count;
    while (n > 0)
    {
        int t;
        cin >> t;
        if (t % 2 == 0)
        {
            even++;
        }
        else
        {
            odds++;
        }
        odds_count.push_back(odds);
        even_count.push_back(even);
        n--;
    }

    while (q > 0)
    {
        int l;
        int r;
        int k;
        cin >> l;
        cin >> r;
        cin >> k;

        int odds_replaced = odds_count[r - 1] - (l == 1 ? 0 : odds_count[l - 2]);
        int even_replaced = even_count[r - 1] - (l == 1 ? 0 : even_count[l - 2]);

        int new_even_count = 0;
        int new_odd_count = 0;
        if (k % 2 == 0)
        {
            new_even_count = even - even_replaced + (r - l + 1);
            new_odd_count = odds - odds_replaced;
        }
        else
        {
            new_even_count = even - even_replaced;
            new_odd_count = odds - odds_replaced + (r - l + 1);
        }
        cout << (new_odd_count % 2 == 1 ? "YES" : "NO") << '\n';
        q--;
    }

    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
