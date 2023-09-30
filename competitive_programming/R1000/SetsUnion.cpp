// Problem: B. Sets and Union
// Contest: Codeforces - Codeforces Round 899 (Div. 2)
// URL: https://codeforces.com/contest/1882/problem/B
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

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    vector<unordered_set<int>> sets;
    unordered_set<int> alls;
    while (n > 0)
    {
        int ki;
        cin >> ki;
        unordered_set<int> set1;
        while (ki > 0)
        {
            int t;
            cin >> t;
            set1.insert(t);
            alls.insert(t);
            ki--;
        }
        sets.push_back(set1);
        n--;
    }

    int maxx = 0;
    for (auto x : alls)
    {
        unordered_set<int> el;
        for (auto y : sets)
        {
            if (y.find(x) == y.end())
            {
                for (auto z : y)
                {
                    el.insert(z);
                }
            }
        }
        maxx = max(maxx, (int)el.size());
    }

    cout << maxx << endl;
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
