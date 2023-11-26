// Problem: C. Fox And Names
// Contest: Codeforces - Codeforces Round 290 (Div. 2)
// URL: https://codeforces.com/contest/510/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

vector<bool> visited(26, false);
set<char> st;
queue<char> topological;

void dfs(char start, vector<vector<char>> &graph)
{
    visited[start - 'a'] = true;
    st.insert(start);
    for (auto x : graph[start - 'a'])
    {
        if (st.find(x) != st.end())
        {
            return;
        }
        else if (!visited[x - 'a'])
        {
            dfs(x, graph);
        }
    }
    st.erase(start);
    topological.push(start);
    return;
}

void Solve()
{
    int n;
    cin >> n;
    vector<string> words(n);
    forn
    {
        cin >> words[i];
    }
    vector<vector<char>> graph;
    for (int i = 0; i < 26; i++)
    {
        graph.pb(vector<char>());
    }
    forn
    {
        for (int j = i + 1; j < n; j++)
        {
            int t = 0;
            for (; t < min(words[i].size(), words[j].size()); t++)
            {
                if (words[i][t] != words[j][t])
                {
                    graph[words[j][t] - 'a'].pb(words[i][t]);
                    break;
                }
            }
            if (t == words[j].size() && words[i].size() > words[j].size())
            {
                cout << "Impossible" << endl;
                return;
            }
        }
    }

    for (int ch = 0; ch < 26; ch++)
    {
        if (!visited[ch])
        {
            dfs('a' + ch, graph);
        }
    }
    if (topological.size() != 26)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        while (topological.size() > 0)
        {
            cout << topological.front();
            topological.pop();
        }
        cout << endl;
    }
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
