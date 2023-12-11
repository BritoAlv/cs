// Problem: C. Contrast Value
// Contest: Codeforces - Educational Codeforces Round 148 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1832/problem/C
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
    int n;
    cin >> n;
    vector<vector<int>> seq;
    vector<int> a;
    forn
    {
        int b;
        cin >> b;
        a.pb(b);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    forn
    {
        int start = i;
        if (start + 1 == n)
        {
            seq.pb({a[i]});
        }
        else
        {
            bool is_increasing;
            int end = i + 1;
            if (a[end] <= a[start])
            {
                is_increasing = false;
            }
            else
            {
                is_increasing = true;
            }
            if (is_increasing)
            {
                while (end + 1 < n && a[end + 1] >= a[end])
                {
                    end++;
                }
                vector<int> to_add;
                for (int j = start; j <= end; j++)
                {
                    to_add.pb(a[j]);
                }
                seq.pb(to_add);
                i = end - 1;
            }
            else
            {
                while (end + 1 < n && a[end + 1] <= a[end])
                {
                    end++;
                }
                vector<int> to_add;
                for (int j = start; j <= end; j++)
                {
                    to_add.pb(a[j]);
                }
                seq.pb(to_add);
                i = end - 1;
            }
        }
    }
    vector<int> r;
    for (auto x : seq)
    {
        r.pb(x[0]);
        r.pb(x[x.size() - 1]);
    }
    long long answer = 0;
    for (int i = 1; i < r.size(); i++)
    {
        if (abs(r[i] - r[i - 1]) != 0)
        {
            answer++;
        }
    }
    cout << answer + 1 << endl;
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