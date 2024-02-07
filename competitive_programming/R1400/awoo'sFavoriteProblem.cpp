// Problem: C. awoo's Favorite Problem
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1697/C
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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<queue<int>> l(3);
    forn
    {
        l[(int)(s[i] - 'a')].push(i);
    }
    forn
    {
        char next = t[i];
        int index = (int)(t[i] - 'a');
        if (l[index].size() == 0)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            auto corresponding = l[index].front();
            l[index].pop();
            if (next == 'a')
            {
                if ((l[2].size() > 0 && l[2].front() <= corresponding) || corresponding > i)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            if (next == 'c')
            {
                if ((l[0].size() > 0 && l[0].front() <= corresponding) || corresponding < i)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
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