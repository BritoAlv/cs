// Problem: C. Update Queries
// Contest: Codeforces - Codeforces Round 954 (Div. 3)
// URL: https://codeforces.com/contest/1986/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<char> s(n);
    forn
    {
        cin >> s[i];
    }
    map<int, int> count;
    form
    {
        int x;
        cin >> x;
        if (count.find(x) == count.end())
        {
            count[x] = 0;
        }
        count[x]++;
    }
    vector<char> chars(m);
    form
    {
        cin >> chars[j];
    }
    sort(chars.begin(), chars.end());
    int lp = 0;
    int rp = m - 1;
    for (auto x : count)
    {
        rp -= x.second - 1;
        s[x.first - 1] = chars[lp];
        lp++;
    }
    forn
    {
        cout << s[i];
    }
    cout << endl;
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