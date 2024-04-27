// Problem: B. Battle Cows
// Contest: Codeforces - Codeforces Global Round 25
// URL: https://codeforces.com/contest/1951/problem/B
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

void update(int lv, int index, vector<vector<vector<int>>> &tree)
{
    int lch = tree[lv][index][2];
    int rch = tree[lv][index][3];
    tree[lv][index][0] = max(tree[lv - 1][lch][0], tree[lv - 1][rch][0]);
    return;
}

void swap(int i, int j, vector<vector<vector<int>>> &tree)
{
    int temp = tree[0][i][0];
    tree[0][i][0] = tree[0][j][0];
    tree[0][j][0] = temp;
    int p1 = i;
    int p2 = j;
    for (int lv = 1; lv < (int)tree.sz; lv++)
    {
        int pp1 = tree[lv - 1][p1][1];
        int pp2 = tree[lv - 1][p2][1];

        update(lv, pp1, tree);
        update(lv, pp2, tree);

        p1 = pp1;
        p2 = pp2;
    }
    return;
}

int count_wins(int i, vector<vector<vector<int>>> &tree)
{
    int lv = 0;
    int act = i;
    int ans = 0;
    while (lv + 1 < (int)tree.sz)
    {
        int parent = tree[lv][act][1];
        vector<int> next = tree[lv + 1][parent];
        if (next[0] == tree[lv][act][0])
        {
            if (next[2] != next[3])
                ans++;
            lv++;
            act = parent;
        }
        else
        {
            break;
        }
    }
    return ans;
}

vector<vector<vector<int>>> tree;

void Solve()
{
    int n, k;
    cin >> n >> k;
    tree.clear();
    tree.pb(vector<vector<int>>());
    forn
    {
        int x;
        cin >> x;
        tree[0].pb({x, -1, -1, -1});
    }
    int actual = 0;
    while ((int)tree[actual].sz >= 2)
    {
        tree.pb(vector<vector<int>>());
        for (int i = 0; i + 1 < (int)tree[actual].sz; i += 2)
        {
            auto winner = max(tree[actual][i][0], tree[actual][i + 1][0]);
            tree[actual][i][1] = tree[actual + 1].sz;
            tree[actual][i + 1][1] = tree[actual + 1].sz;
            tree[actual + 1].pb({winner, -1, i, i + 1});
        }
        if (tree[actual].sz % 2 == 1)
        {
            tree[actual][tree[actual].sz - 1][1] = tree[actual + 1].sz;
            tree[actual + 1].pb(
                {tree[actual][tree[actual].sz - 1][0], -1, (int)tree[actual].sz - 1, (int)tree[actual].sz - 1});
        }
        actual++;
    }
    k--;
    int maxx = -1;
    forn
    {
        swap(i, k, tree);
        int wins = count_wins(i, tree);
        if (maxx == -1 || maxx < wins)
        {
            maxx = wins;
        }
        swap(i, k, tree);
    }
    cout << maxx << endl;
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