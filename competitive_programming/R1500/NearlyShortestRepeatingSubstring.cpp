// Problem: E. Nearly Shortest Repeating Substring
// Contest: Codeforces - Codeforces Round 937 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1950/E
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

int prove(int len, vector<char> &s)
{
    int n = s.sz;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < n / len; j++)
        {
            if (s[j * len + i] != s[i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int w(int len, vector<char> &s)
{
    int n = s.sz;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < n / len; j++)
        {
            if (s[j * len + i] != s[i])
            {
                // check the two options.
                vector<char> cc(n);
                vector<char> dd(n);
                forn
                {
                    cc[i] = s[i];
                    dd[i] = s[i];
                }
                cc[j * len + i] = s[i];
                dd[i] = s[j * len + i];
                return prove(len, cc) || prove(len, dd);
            }
        }
    }
    return 1;
}

void Solve()
{
    int n;
    cin >> n;
    vector<char> s(n);
    forn
    {
        cin >> s[i];
    }
    set<int> divisors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    int minn = n;
    for (auto x : divisors)
    {
        if (w(x, s))
        {
            minn = min(x, minn);
        }
    }
    cout << minn << endl;
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
