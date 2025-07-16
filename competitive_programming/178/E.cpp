// Problem: E. Unpleasant Strings
// Contest: Codeforces - Educational Codeforces Round 178 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2104/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// You might break and that's okay.
// Tags:
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    vector<set<int>> S(k, set<int>());
    vector<int> pos(k, n);
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        S[(int)(a[i] - 'a')].insert(i);
        pos[(int)(a[i] - 'a')] = i;
        int maxx = pos[0];
        forj(1, k - 1) maxx = max(maxx, pos[j]);
        if (maxx == n)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 1 + dp[maxx + 1];
        }
    }
    // print(dp);
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int pos = -1;
        fori(0, (int)s.size() - 1)
        {
            int letter = (int)(s[i] - 'a');
            auto pt = S[letter].lower_bound(pos + 1);
            if (pt == S[letter].end())
            {
                pos = -1;
                break;
            }
            else
            {
                pos = *pt;
            }
        }
        if (pos == -1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << dp[pos + 1] << endl;
        }
    }
}

int main()
{
    test_cases = 1;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}