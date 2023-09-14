// Problem: B. Napoleon Cake
// Contest: Codeforces - Codeforces Round 707 (Div. 2, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/problemset/problem/1501/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: well brute force for implementing it I did,
// it has a better solution.
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
    int n;
    cin >> n;
    vector<pair<int, int>> pairs;
    forn
    {
        int t;
        cin >> t;
        if (t > 0)
        {
            pairs.push_back(make_pair(max(1, i + 1 - t + 1), i + 1));
        }
    }
    sort(pairs.begin(), pairs.end());

    int a[n];
    forn
    {
        a[i] = 0;
    }

    int index = 0;
    while (index < pairs.size())
    {
        int max_advance = 1;
        int start = pairs[index].first;
        int end = pairs[index].second;
        while (index + max_advance < pairs.size() && pairs[index + max_advance].first <= end)
        {
            end = max(end, pairs[index + max_advance].second);
            max_advance++;
        }
        for (int i = start; i <= end; i++)
        {
            a[i - 1] = 1;
        }
        index = index + max_advance;
    }

    forn
    {
        cout << a[i] << wp;
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
