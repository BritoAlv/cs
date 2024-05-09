// Problem: D. Permutation Game
// Contest: Codeforces - Codeforces Round 943 (Div. 3)
// URL: https://codeforces.com/contest/1968/problem/D
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

ull get_best(int sp, int k, vector<int> &p, vector<int> &a)
{
    set<int> visited;
    vector<ull> candidates;
    visited.insert(sp);
    candidates.pb((ull)k * a[sp]);
    ull prev_score = 0;
    fork
    {
        prev_score += a[sp];
        if (visited.find(p[sp]) != visited.end())
        {
            break;
        }
        else
        {
            sp = p[sp];
            visited.insert(sp);
            candidates.pb((ull)(k - 1 - i) * a[sp] + prev_score);
        }
    }
    sort(candidates.begin(), candidates.end());
    return candidates.back();
}

void Solve()
{
    int n, pb, ps, k;
    cin >> n >> k >> pb >> ps;
    vector<int> p(n + 1);
    vector<int> a(n + 1);
    forn
    {
        cin >> p[i + 1];
    }
    forn
    {
        cin >> a[i + 1];
    }
    auto b = get_best(pb, k, p, a);
    auto c = get_best(ps, k, p, a);
    if (b < c)
    {
        cout << "Sasha" << endl;
    }
    else if (b > c)
    {
        cout << "Bodya" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }
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
