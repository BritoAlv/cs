// Problem: B. YetnotherrokenKeoard
// Contest: Codeforces - Codeforces Round 913 (Div. 3)
// URL: https://codeforces.com/contest/1907/problem/B
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
    string S;
    cin >> S;
    stack<pair<int, char>> M;
    stack<pair<int, char>> m;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'b')
        {
            if (m.size() > 0)
            {
                m.pop();
            }
        }
        else if (S[i] == 'B')
        {
            if (M.size() > 0)
            {
                M.pop();
            }
        }
        else if (islower(S[i]))
        {
            m.push({i, S[i]});
        }
        else
        {
            M.push({i, S[i]});
        }
    }
    vector<pair<int, char>> string;
    while (m.size() > 0)
    {
        string.pb(m.top());
        m.pop();
    }
    while (M.size() > 0)
    {
        string.pb(M.top());
        M.pop();
    }
    sort(string.begin(), string.end());
    for (auto x : string)
    {
        cout << x.second;
    }
    cout << endl;
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
