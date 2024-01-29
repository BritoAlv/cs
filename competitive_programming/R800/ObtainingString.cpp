// Problem: B. Obtaining the String
// Contest: Codeforces - Codeforces Round 501 (Div. 3)
// URL: https://codeforces.com/contest/1015/problem/B
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
#define ull unsigned long long
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int count[26];
    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;
    }
    string s, t;
    cin >> s >> t;
    forn
    {
        count[s[i] - 'a']++;
    }
    forn
    {
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i += 1)
    {
        if (count[i] != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> indexes;
    forn
    {
        if (s[i] != t[i])
        {
            int start = i;
            int end = i;
            while (end + 1 < n && s[end + 1] != t[i])
            {
                end++;
            }
            for (int j = end; j >= start; j--)
            {
                indexes.pb(j + 1);
                char temp = s[j + 1];
                s[j + 1] = s[j];
                s[j] = temp;
            }
        }
    }
    cout << indexes.size() << endl;
    for (auto y : indexes)
    {
        cout << y << wp;
    }
    cout << endl;
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
