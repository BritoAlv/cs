// Problem: A. Anti Light's Cell Guessing
// Contest: Codeforces - Codeforces Global Round 17
// URL: https://codeforces.com/problemset/problem/1610/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: notice that if you put two in two adyacent cornets
// then from the point of view of one all of the cell with
// the same manhattan distance are in the same diagonal. which is not constant
// for the another marked cell
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << 0 << endl;
    }
    else if (n == 1 || m == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }

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
