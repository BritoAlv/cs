// Problem: C. Everything Nim
// Contest: Codeforces - Codeforces Round 941 (Div. 2)
// URL: https://codeforces.com/contest/1966/problem/C
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    set<int> a;
    forn
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    int offset = 0;
    int turn = 1;
    while (true)
    {
        int nn = *a.begin() - offset;
        if (nn != 1 || a.sz == 1)
        {
            cout << (turn ? "Alice" : "Bob") << endl;
            return;
        }
        else
        {
            int next = *a.begin();
            a.erase(next);
            offset++;
            turn = !turn;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
