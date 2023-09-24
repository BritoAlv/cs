// Problem: B. Monsters
// Contest: Codeforces - Educational Codeforces Round 152 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1849/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: this problem should be called sort by remainders
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int k;

bool comparator(pair<int, int> a, pair<int, int> b)
{
    if (a.second % k == b.second % k)
    {
        return a.first < b.first;
    }
    else
    {
        if (a.second % k == 0)
        {
            return true;
        }
        else if (b.second % k == 0)
        {
            return false;
        }
        else
        {
            return (a.second % k) > (b.second % k);
        }
    }
}

void Solve()
{
    int n;
    cin >> n >> k;
    pair<int, int> a[n];
    forn
    {
        int t;
        cin >> t;
        a[i] = make_pair(i, t);
    }
    sort(a, a + n, comparator);
    forn
    {
        cout << a[i].first + 1 << wp;
    }
    cout << endl;
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
