// Problem: B. Notepad#
// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1766/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int hash1[n - 1];
    int hash2[n - 1];
    int hash3[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        hash1[i] = 3 * (s[i] - 'a') + 5 * (s[i + 1] - 'a');
        hash2[i] = 7 * (s[i] - 'a') + 4 * (s[i + 1] - 'a');
        hash3[i] = 11 * hash1[i] + 13 * hash2[i];
    }
    vector<int> vals2;
    for (int i = 0; i < n - 1; i++)
    {
        vals2.push_back(hash3[i]);
        if ((i + 1 < n - 1) && (hash3[i] == hash3[i + 1]))
        {
            i++;
        }
    }
    unordered_set<int> vals;
    for (int i = 0; i < vals2.size(); i++)
    {
        vals.insert(vals2[i]);
    }
    if (vals.size() < vals2.size())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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