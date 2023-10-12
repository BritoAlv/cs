// Problem: B. Helmets in Night Light
// Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
// URL: https://codeforces.com/contest/1877/problem/B
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

int comparer(pair<int, int> A, pair<int, int> B)
{
    if (A.first < B.first)
    {
        return 1;
    }
    else if (A.first > B.first)
    {
        return 0;
    }
    else
    {
        return A.second > B.second;
    }
}

void Solve()
{
    int n, p;
    cin >> n >> p;
    int a[n];
    int b[n];
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    vector<pair<int, int>> pp;
    forn
    {
        pp.push_back(make_pair(b[i], a[i]));
    }
    sort(pp.begin(), pp.end(), comparer);

    int person_tell = 1;
    long long cost = p;
    for (int i = 0; i < n && person_tell < n; i++)
    {
        if (pp[i].first > p)
        {
            cost += (long long)(n - person_tell) * p;
            break;
        }
        else
        {
            cost += (long long)min(pp[i].second, n - person_tell) * pp[i].first;
            person_tell += min(pp[i].second, n - person_tell);
        }
    }
    cout << cost << endl;
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
