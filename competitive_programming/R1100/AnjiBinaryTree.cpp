// Problem: C. Anji's Binary Tree
// Contest: Codeforces - Codeforces Round 911 (Div. 2)
// URL: https://codeforces.com/contest/1900/problem/C
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int i = 0; i < m; i++)
#define pb push_back

using namespace std;

int answer;

void dfs(int n, int prev_ans, vector<char> &marks, vector<pair<int, int>> &graph)
{
    if (graph[n].first == 0 && graph[n].second == 0)
    {
        answer = min(prev_ans, answer);
        return;
    }
    if (graph[n].first != 0)
    {
        int to_passL = prev_ans;
        if (marks[n] != 'L')
        {
            to_passL++;
        }
        dfs(graph[n].first - 1, to_passL, marks, graph);
    }
    if (graph[n].second != 0)
    {
        int to_passR = prev_ans;
        if (marks[n] != 'R')
        {
            to_passR++;
        }
        dfs(graph[n].second - 1, to_passR, marks, graph);
    }
}

void Solve()
{
    int n;
    cin >> n;
    vector<char> marks(n);
    forn
    {
        cin >> marks[i];
    }
    vector<pair<int, int>> graph;
    forn
    {
        int a, b;
        cin >> a >> b;
        graph.pb({a, b});
    }
    answer = n;
    dfs(0, 0, marks, graph);
    cout << answer << endl;
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
