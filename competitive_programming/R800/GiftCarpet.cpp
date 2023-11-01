// Problem: A. Gift Carpet
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> table;
    for (int i = 0; i < n; i++)
    {
        table.push_back(vector<char>(m));
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }
    queue<char> st;
    st.push('v');
    st.push('i');
    st.push('k');
    st.push('a');
    for (int fc = 0; fc < m; fc++)
    {
        forn
        {
            if (table[i][fc] == st.front())
            {
                st.pop();
                if (st.size() == 0)
                {
                    cout << "YES" << endl;
                    return;
                }
                break;
            }
        }
    }
    cout << "NO" << endl;
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
