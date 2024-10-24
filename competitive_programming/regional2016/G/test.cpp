#include <bits/stdc++.h>

using namespace std;

long long base1 = 37;
long long base2 = 19;
long long mod = 998244353;

long long f_pow(long long base, long long exp, long long mod)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base % mod;
    long long middle = f_pow(base, exp / 2, mod);
    middle *= middle;
    middle %= mod;
    if (exp % 2)
    {
        middle *= base;
        middle %= mod;
    }
    return middle;
}

long long inv(long long base, long long mod)
{
    return f_pow(base, mod - 2, mod);
}

int compare(map<int, long long> &hashes_p, map<char, long long> &A,
            map<char, queue<int> > &pos)
{
    if (A.size() != hashes_p.size())
    {
        return 0;
    }
    vector<pair<int, long long> > pos_vs_hash;
    for (auto &z : pos)
    {
        pair<int, long long> ww = {z.second.front(), A[z.first]};
        pos_vs_hash.push_back(ww);
    }
    sort(pos_vs_hash.begin(), pos_vs_hash.end());
    int offset = pos_vs_hash[0].first;
    long long invv1 = inv(f_pow(base1, offset, mod), mod);
    for (auto &z : hashes_p)
    {
        long long hash21 = pos_vs_hash[z.first].second;
        if (offset > 0)
        {
            hash21 *= invv1;
            hash21 %= mod;
        }
        long long hash2 = hash21;
        if (z.second != hash2)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> p(n);
    map<int, int> map_l;
    map<int, long long> hashes_p;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (map_l.find(p[i]) == map_l.end())
        {
            map_l.emplace(p[i], map_l.size());
            long long aa = 0;
            hashes_p.emplace(map_l[p[i]], aa);
        }
    }

    for (int i = 0; i < n; i++)
    {
        long long to_add1 = f_pow(base1, i + 1, mod);
        int mapped = map_l[p[i]];
        long long zz = (hashes_p[mapped] + to_add1) % mod;
        hashes_p[mapped] = zz;
    }
    int ans = 0;
    map<char, queue<int> > positions;
    map<char, long long> hashes_sum;
    for (int i = 0; i < s.size(); i++)
    {
        long long to_add1 = f_pow(base1, i + 1, mod);
        if (positions.find(s[i]) == positions.end())
        {
            positions.emplace(s[i], queue<int>());
            hashes_sum.emplace(s[i], 0);
        }
        positions[s[i]].push(i);
        long long zz = (hashes_sum[s[i]] + to_add1) % mod;
        hashes_sum[s[i]] = zz;
        if (i >= n)
        {
            int to_rest = positions[s[i - n]].front();
            positions[s[i - n]].pop();
            if (positions[s[i - n]].size() == 0)
            {
                positions.erase(s[i - n]);
                hashes_sum.erase(s[i - n]);
            }
            else
            {
                long long to_rest_h1 = f_pow(base1, to_rest + 1, mod);
                long long xx = (mod + hashes_sum[s[i - n]] - to_rest_h1) % mod;
                hashes_sum[s[i - n]] = xx;
            }
        }
        if (i >= n - 1)
        {
            if (compare(hashes_p, hashes_sum, positions))
            {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}