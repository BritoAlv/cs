// Problem: C. Premutation
// Contest: Codeforces - Codeforces Round 847 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1790/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Math Proof: notice that there are two candidates for
// each position, so choose the one that is not candidate for
// the next position.
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
    int a[n];
    forn
    {
        a[i] = 0;
    }
    vector<unordered_set<int>> candidates;
    int counter = 0;
    while (counter < n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int t;
            cin >> t;
            if (candidates.size() < i + 1)
            {
                unordered_set<int> to_add;
                to_add.insert(t);
                candidates.push_back(to_add);
            }
            else
            {
                candidates[i].insert(t);
            }
        }
        counter++;
    }
    for (int i = 0; i < candidates.size() - 1; i++)
    {
        if (a[i] == 0)
        {
            auto it = candidates[i].begin();
            if (candidates[i + 1].find(*it) == candidates[i + 1].end())
            {
                a[i] = *it;
                it++;
                a[i + 1] = *(it);
            }
            else
            {
                a[i + 1] = *it;
                it++;
                a[i] = *it;
            }
        }
        else
        {
            auto it = candidates[i].begin();
            if (a[i] == *it)
            {
                it++;
                a[i + 1] = *(it);
            }
            else
            {
                a[i + 1] = *it;
            }
        }
    }
    auto it = candidates[candidates.size() - 1].begin();
    if (a[n - 2] == *it)
    {
        it++;
        a[n - 1] = *it;
    }
    else
    {
        a[n - 1] = *it;
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
