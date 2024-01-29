// Problem: C. Fighting Tournament
// Contest: Codeforces - Codeforces Round 814 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1719/C
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

void Solve()
{
    int n, q;
    cin >> n >> q;
    deque<int> A;
    vector<vector<pair<int, int>>> ans;
    int monster_pos[n];
    forn
    {
        int c;
        cin >> c;
        A.pb(c - 1);
        monster_pos[i] = c - 1;
        ans.pb(vector<pair<int, int>>());
    }
    int rounds_played = 0;
    while (A.front() != n - 1)
    {
        int first = A.front();
        A.pop_front();
        int second = A.front();
        A.pop_front();
        rounds_played++;
        if (first < second)
        {
            A.push_front(second);
            A.push_back(first);
            ans[second].pb({rounds_played, ans[second].size() + 1});
        }
        else
        {
            A.push_front(first);
            A.push_back(second);
            ans[first].pb({rounds_played, ans[first].size() + 1});
        }
    }
    while (q > 0)
    {
        int i, k;
        cin >> i >> k;
        // how may victories got i player in rounds_played.
        int first_part = min(k, rounds_played);
        int vic = 0;
        i = monster_pos[i - 1];
        pair<int, int> to_find = {first_part, n + 1};
        auto it = lower_bound(ans[i].begin(), ans[i].end(), to_find);
        if (it != ans[i].begin())
        {
            it--;
            vic += (*it).second;
        }
        k -= first_part;
        if (k > 0 && i == n - 1)
        {
            vic += k;
        }
        cout << vic << endl;
        q--;
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