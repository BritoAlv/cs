// Problem: A. Red Versus Blue
// Contest: Codeforces - Codeforces Round 782 (Div. 2)
// URL: https://codeforces.com/contest/1659/problem/A
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
    int n, r, b;
    cin >> n >> r >> b;
    char minn = min(r, b) == r ? 'R' : 'B';
    char maxx = minn == 'R' ? 'B' : 'R';
    vector<int> pieces;
    for (int i = 0; i <= min(r, b); i++)
    {
        pieces.push_back(max(r, b) / (min(r, b) + 1));
    }
    for (int i = 0; i < max(r, b) % (min(r, b) + 1); i++)
    {
        pieces[i] += 1;
    }
    for (int i = 0; i < pieces.size(); i++)
    {
        for (int j = 0; j < pieces[i]; j++)
        {
            cout << maxx;
        }
        if (i != pieces.size() - 1)
        {
            cout << minn;
        }
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
