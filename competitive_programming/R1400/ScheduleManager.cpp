// Problem: C. Schedule Management
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

void Solve()
{
    int m, n;
    cin >> m >> n;
    multiset<int> count;
    vector<int> counts(m);
    forn
    {
        int c;
        cin >> c;
        counts[--c]++;
    }
    form
    {
        count.insert(counts[j]);
    }
    int low = *(count.begin());
    int great = *(count.rbegin());
    while (great - low >= 3)
    {
        count.erase(count.find(low));
        count.erase(count.find(great));
        low += 2;
        great -= 1;
        count.insert(low);
        count.insert(great);
        low = *(count.begin());
        great = *(count.rbegin());
    }
    cout << *(count.rbegin()) << endl;
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