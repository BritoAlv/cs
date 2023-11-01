// Problem: F. Minimum Maximum Distance
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: notice that the answer will be ceil ( (some distance + 1) / 2) from the case where there are two labelled vertices. If I find the lca of the labelled vertices, the longest distance will be a path in that tree, but because it is unique it can be found in the original tree also.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n, total_marked;
    cin >> n >> total_marked;
    vector<int> marked(total_marked);
    for (int i = 0; i < total_marked; i++)
    {
        cin >> marked[i];
        marked[i]--;
    }
    vector<vector<int>> adyacency;
    forn
    {
        adyacency.push_back(vector<int>());
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adyacency[a - 1].push_back(b - 1);
        adyacency[b - 1].push_back(a - 1);
    }

    int d[n];
    forn
    {
        d[i] = -1;
    }
    d[marked[0]] = 0;
    queue<int> q;
    q.push(marked[0]);

    while (q.size() > 0)
    {
        int next = q.front();
        q.pop();
        for (auto x : adyacency[next])
        {
            if (d[x] == -1)
            {
                d[x] = d[next] + 1;
                q.push(x);
            }
        }
    }

    int max = d[marked[0]];
    int index_max = 0;
    for (int i = 1; i < marked.size(); i++)
    {
        if (d[marked[i]] > max)
        {
            max = d[marked[i]];
            index_max = i;
        }
    }

    queue<int> qqq;
    int d2[n];
    for (int i = 0; i < n; i++)
    {
        d2[i] = -1;
    }
    d2[marked[index_max]] = 0;
    qqq.push(marked[index_max]);
    while (qqq.size() > 0)
    {
        int next = qqq.front();
        qqq.pop();
        for (auto m : adyacency[next])
        {
            if (d2[m] == -1)
            {
                d2[m] = d2[next] + 1;
                qqq.push(m);
            }
        }
    }

    int maxx = 0;
    for (int i = 0; i < marked.size(); i++)
    {
        if (d2[marked[i]] > maxx)
        {
            maxx = d2[marked[i]];
        }
    }
    cout << (maxx + 1) / 2 << endl;

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
