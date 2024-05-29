// Problem: B. Codeforces Subsequences
// Contest: Codeforces - Codeforces Global Round 8
// URL: https://codeforces.com/contest/1368/problem/B
// Memory Limit: 512 MB
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

void Solve()
{
    long long k;
    cin >> k;
    long long ac = 1;
    vector<int> count(10, 1);
    while (ac < k)
    {
        for (int i = 0; i < 10 && ac < k; i++)
        {
            ac /= count[i];
            count[i]++;
            ac *= count[i];
        }
    }
    auto c = "codeforces";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            cout << c[i];
        }
    }
    cout << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
