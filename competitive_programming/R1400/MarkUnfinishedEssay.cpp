// Problem: C. Mark and His Unfinished Essay
// Contest: Codeforces - Codeforces Round 807 (Div. 2)
// URL: https://codeforces.com/contest/1705/problem/C
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

char a[200000];
int n, c, q;
vector<pair<long long, long long>> segments;
char get(long long position)
{
    if (position < n)
    {
        return a[position];
    }
    else
    {
        long long initial_len = n - 1;
        for (int i = 0; i < segments.size(); i++)
        {
            long long old_len = initial_len;
            initial_len += segments[i].second - segments[i].first + 1;
            if (initial_len >= position)
            {
                return get(segments[i].first + (position - old_len - 1));
            }
        }
    }
}

void Solve()
{
    cin >> n >> c >> q;
    segments.clear();
    forn
    {
        cin >> a[i];
    }
    for (int i = 0; i < c; i++)
    {
        long long a, b;
        cin >> a >> b;
        segments.pb({--a, --b});
    }
    for (int i = 0; i < q; i++)
    {
        long long k;
        cin >> k;
        cout << get(--k) << endl;
    }
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
