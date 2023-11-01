// Problem: C. Medium Design
// Contest: Codeforces - Codeforces Round 904 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1884/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> start;
    vector<int> end;
    unordered_set<int> candidates;
    vector<int> one_contained;
    vector<int> end_contained;
    int both = 0;
    forn
    {
        int a, b;
        cin >> a >> b;
        start.push_back(a);
        end.push_back(b);
        vector<int> cc;
        candidates.insert(a);
        candidates.insert(b);
        if (a == 1)
        {
            one_contained.push_back(b);
        }
        if (b == m)
        {
            end_contained.push_back(a);
        }
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    sort(one_contained.begin(), one_contained.end());
    sort(end_contained.begin(), end_contained.end());

    int maxx = -1;
    for (auto x : candidates)
    {
        int starr = start.end() - lower_bound(start.begin(), start.end(), x + 1);
        int endd = upper_bound(end.begin(), end.end(), x - 1) - end.begin();

        int one_part = one_contained.end() - lower_bound(one_contained.begin(), one_contained.end(), x);
        int end_part = upper_bound(end_contained.begin(), end_contained.end(), x) - end_contained.begin();
        if ((n - (starr + endd) - min(one_part, end_part)) > maxx)
        {
            maxx = (n - (starr + endd) - min(one_part, end_part));
        }
    }
    cout << maxx << endl;
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
