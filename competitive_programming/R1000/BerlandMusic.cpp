// Problem: B. Berland Music
// Contest: Codeforces - Educational Codeforces Round 120 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1622/problem/B
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

int comparer(pair<int, int> A, pair<int, int> B)
{
    if (A.second == 1 && B.second == 0)
    {
        return 1;
    }
    else if (A.second == 0 && B.second == 1)
    {
        return 0;
    }
    else
    {
        return A.first > B.first;
    }
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    unordered_map<int, int> B;
    forn
    {
        cin >> a[i];
        B[a[i]] = i;
    }
    vector<char> S(n);
    forn
    {
        cin >> S[i];
    }

    pair<int, int> b[n];
    forn
    {
        b[i] = {a[i], (S[i] == '0' ? 0 : 1)};
    }
    sort(b, b + n, comparer);
    forn
    {
        a[B[b[i].first]] = n - i;
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
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}