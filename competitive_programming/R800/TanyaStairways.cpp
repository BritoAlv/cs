// Problem: A. Tanya and Stairways
// Contest: Codeforces - Codeforces Round 496 (Div. 3)
// URL: https://codeforces.com/contest/1005/problem/A
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
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<int> sequences;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    forn
    {
        int start = i;
        int end = i;
        while (end + 1 < n && a[end + 1] > a[end])
        {
            end++;
        }
        sequences.pb(end - start + 1);
        i = end;
    }
    cout << sequences.size() << endl;
    for (auto x : sequences)
    {
        cout << x << wp;
    }
    cout << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}