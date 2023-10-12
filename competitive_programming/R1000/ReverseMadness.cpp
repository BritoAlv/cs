// Problem: D. Reverse Madness
// Contest: Codeforces - Codeforces Round 900 (Div. 3)
// URL: https://codeforces.com/contest/1878/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
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
    int n, k;
    cin >> n >> k;
    string S;
    cin >> S;
    int l[k];
    int r[k];
    unordered_set<int> lis;
    int positions[n];
    forn
    {
        positions[i] = i;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> l[i];
        lis.insert(l[i]);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> r[i];
    }
    vector<pair<int, int>> modifications;
    for (int i = 0; i < k; i++)
    {
        int a = l[i];
        int b = r[i];
        while (a < b)
        {
            modifications.push_back(make_pair(a, b));
            a++;
            b--;
        }
    }
    unordered_map<int, int> count;
    int q;
    cin >> q;
    while (q > 0)
    {
        int t;
        cin >> t;
        if (count.find(t) == count.end())
        {
            count[t] = 0;
        }
        count[t]++;
        q--;
    }
    vector<int> real_counts(modifications.size());
    for (int i = 0; i < modifications.size(); i++)
    {
        int x1 = modifications[i].first;
        int x2 = modifications[i].second;

        if (lis.find(x1) != lis.end())
        {
            real_counts[i] = count[x1] + count[x2];
        }
        else
        {
            real_counts[i] = real_counts[i - 1] + count[x1] + count[x2];
        }
    }
    for (int i = 0; i < modifications.size(); i++)
    {
        if (real_counts[i] % 2 == 1)
        {
            int temp = positions[modifications[i].first - 1];
            positions[modifications[i].first - 1] = positions[modifications[i].second - 1];
            positions[modifications[i].second - 1] = temp;
        }
    }
    vector<char> final(n);
    forn
    {
        final[i] = S[positions[i]];
    }
    forn
    {
        cout << final[i];
    }
    cout << endl;
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
