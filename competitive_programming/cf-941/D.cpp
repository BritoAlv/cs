// Problem: D. Missing Subsequence Sum
// Contest: Codeforces - Codeforces Round 941 (Div. 2)
// URL: https://codeforces.com/contest/1966/problem/D
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

int checker(int n, int k, vector<int> &seq)
{
    if (seq.sz > 25)
    {
        return 0;
    }
    set<int> sums;
    for (int i = 0; i < (1 << seq.sz); i++)
    {
        int sum = 0;
        for (int j = 0; j < seq.sz; j++)
        {
            if ((i & (1 << j)) > 0)
            {
                sum += seq[j];
            }
        }
        sums.insert(sum);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != k && sums.find(i) == sums.end())
        {
            return 0;
        }
        if (i == k && sums.find(i) != sums.end())
        {
            return 0;
        }
    }
    return 1;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> part1;
    int st = k;
    while (st >= 2)
    {
        part1.pb(st / 2);
        st = st / 2 + st % 2;
    }
    vector<int> part2;
    vector<int> seq;
    for (int i = 0; i <= 20; i++)
    {
        if ((1 << i) > k && (1 << i) <= n)
        {
            part2.pb((1 << i));
        }
    }
    reverse(part2.begin(), part2.end());
    st = k + 1;
    while (part2.sz + part1.sz < 25)
    {
        part2.pb(st++);
    }
    for (auto x : part2)
    {
        seq.pb(x);
    }
    for (auto x : part1)
    {
        seq.pb(x);
    }
    cout << seq.sz << endl;
    for (auto x : seq)
    {
        cout << x << wp;
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
