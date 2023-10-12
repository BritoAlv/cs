// Problem: D. Effects of Anti Pimples
// Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
// URL: https://codeforces.com/contest/1877/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

#define MOD 998244353

int comparer(pair<int, int> A, pair<int, int> B)
{
    if (A.first > B.first)
    {
        return 1;
    }
    else if (A.first < B.first)
    {
        return 0;
    }
    return A.second < B.second;
}

long long pow_mod(int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    if (exp == 1)
    {
        return 2;
    }
    else
    {
        long long ans = pow_mod(exp / 2);
        ans *= ans;
        ans = ans % MOD;
        if (exp % 2 == 1)
        {
            ans = ans * 2;
            ans = ans % MOD;
        }
        return ans;
    }
}

void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    int asigned[n];
    forn
    {
        int a;
        cin >> a;
        p.push_back(make_pair(a, i + 1));
        asigned[i] = 0;
    }
    unordered_map<int, int> rev_ind;
    sort(p.begin(), p.end(), comparer);
    forn
    {
        rev_ind[p[i].second] = i;
    }
    for (int h = 1; h <= n; h++)
    {
        int min_index = rev_ind[h];
        for (int l = h; l <= n; l += h)
        {
            if (rev_ind[l] < min_index)
            {
                min_index = rev_ind[l];
            }
        }
        asigned[p[min_index].second - 1]++;
    }
    long long ans = 0;
    int already_seen = 0;
    forn
    {
        long long aport = pow_mod(asigned[p[i].second - 1]) - 1;
        aport *= pow_mod(n - already_seen - asigned[p[i].second - 1]);
        aport %= MOD;
        aport *= p[i].first;
        aport %= MOD;
        already_seen += asigned[p[i].second - 1];
        ans += aport;
        ans %= MOD;
    }

    cout << ans << endl;
    return;
}

int main()
{
    Solve();
    return 0;
}
