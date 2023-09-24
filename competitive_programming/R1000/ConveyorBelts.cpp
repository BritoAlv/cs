// Problem: B. Conveyor Belts
// Contest: Codeforces - Codeforces Round 863 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1811/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Math Proof: how describe that geometrical place.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int get_conveyor(int x1, int y1, int n)
{
    if (x1 > n / 2)
    {
        x1 = n - x1 + 1;
    }
    if (y1 > n / 2)
    {
        y1 = n - y1 + 1;
    }
    return min(x1, y1);
}

void Solve()
{
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    cout << abs(get_conveyor(x1, y1, n) - get_conveyor(x2, y2, n)) << endl;
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
