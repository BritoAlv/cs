// Problem: C. Make It Permutation
// Contest: Codeforces - CodeTON Round 4 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/problemset/problem/1810/C
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
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    long long c, d;
    long long cost = 0;
    cin >> n >> c >> d;
    set<int> a;
    vector<int> aa;
    forn
    {
        int t;
        cin >> t;
        if (a.find(t) == a.end())
        {
            a.insert(t);
        }
        else
        {
            cost += c;
        }
    }
    for (auto x : a)
    {
        aa.pb(x);
    }
    long long minn = c * a.size() + d;
    for (auto j : a)
    {
        // how many numbers >= 1 and less than j in the array.
        // how many numbers > j in the array.
        int greater_j = aa.end() - lower_bound(aa.begin(), aa.end(), j + 1);
        int less_equal_j = upper_bound(aa.begin(), aa.end(), j) - aa.begin();
        minn = min(minn, (j - less_equal_j) * d + greater_j * c);
    }
    cout << cost + minn << endl;
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