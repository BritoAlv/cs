// Problem: D. Lonely Mountain Dungeons
// Contest: Codeforces - Codeforces Round 924 (Div. 2)
// URL: https://codeforces.com/contest/1928/problem/D#
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

long long n, b, x;
vector<int> race_count;
long long simulate(int squads)
{
    long long total_score = -(squads - 1) * x;
    vector<vector<int>> qq(n);
    forn
    {
        for (int j = 0; j < race_count[i]; j++)
        {
            qq[i].pb(j % squads);
        }
    }
    long long n_p = 0;
    forn
    {
        sort(qq[i].begin(), qq[i].end());
        long long ans = 0;
        long long total = qq[i].size();
        long long current = 0;
        for (int j = 0; j < qq[i].size(); j++)
        {
            if (j > 0 && qq[i][j] != qq[i][j - 1])
            {
                ans += current * (total - current);
                total -= current;
                current = 0;
            }
            current++;
        }
        n_p += ans;
    }
    return total_score + n_p * b;
}

void Solve()
{
    race_count.clear();
    cin >> n >> b >> x;
    forn
    {
        int c;
        cin >> c;
        race_count.pb(c);
    }
    int low = 1;
    int gt = 2 * 100000;
    while (gt - low > 1)
    {
        int middle = (gt + low) / 2;
        long long r1 = simulate(middle - 1);
        long long r2 = simulate(middle);
        if (r1 <= r2)
        {
            low = middle;
        }
        else
        {
            gt = middle;
        }
    }
    vector<long long> r;
    r.pb(simulate(low));
    r.pb(simulate(low + 1));
    r.pb(simulate(low + 2));
    sort(r.begin(), r.end());
    cout << r[2] << endl;
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