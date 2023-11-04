// Problem: B. Triangles on a Rectangle
// Contest: Codeforces - Educational Codeforces Round 119 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1620/problem/B
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

void Solve()
{
    long long w, h;
    cin >> w >> h;
    vector<vector<int>> parts;
    for (int i = 0; i < 4; i++)
    {
        int k;
        cin >> k;
        vector<int> coord(k);
        for (int j = 0; j < k; j++)
        {
            cin >> coord[j];
        }
        parts.push_back(vector<int>{coord[0], coord[k - 1]});
    }

    long long area1 = abs(parts[0][0] - parts[0][1]) * h;
    long long area2 = abs(parts[1][0] - parts[1][1]) * h;
    long long area3 = abs(parts[2][0] - parts[2][1]) * w;
    long long area4 = abs(parts[3][0] - parts[3][1]) * w;
    cout << max(max(area1, area2), max(area3, area4)) << endl;
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
