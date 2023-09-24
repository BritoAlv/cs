// Problem: E. Building an Aquarium
// Contest: Codeforces - Codeforces Round 898 (Div. 4)
// URL: https://codeforces.com/contest/1873/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: nice problem, just implement it without
// bad logic
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
    int n, x;
    cin >> n >> x;
    map<int, int> counts;
    forn
    {
        int t;
        cin >> t;
        if (counts.find(t) != counts.end())
        {
            counts[t]++;
        }
        else
        {
            counts[t] = 1;
        }
    }
    auto it = counts.begin();
    long long water_used = 0;
    int height = 0;
    int cant_blocks = 0;
    while (water_used <= x)
    {
        if (it == counts.end() || (water_used + (long long)((*it).first - height) * cant_blocks) > x)
        {
            break;
        }
        water_used += (long long)((*it).first - height) * cant_blocks;
        height = (*it).first;
        cant_blocks += (*it).second;
        it++;
    }
    if (x - water_used >= 0)
    {
        height += (x - water_used) / cant_blocks;
        water_used += cant_blocks * ((x - water_used) / cant_blocks);
    }
    while (water_used <= x)
    {
        height++;
        water_used += cant_blocks;
    }
    cout << height - 1 << endl;
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