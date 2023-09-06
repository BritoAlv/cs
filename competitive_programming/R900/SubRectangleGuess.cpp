// Problem: A. Subrectangle Guess
// Contest: Codeforces - Codeforces Round 801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/problemset/problem/1695/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: the answer is the max area between all the rectangles that contains the position where is the max number, for any are smaller than this number is possible to make a rectangle that do not contain the smaller number, and any rectangle with area greater than this will include it,
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    int m;
    cin >> n >> m;

    int r1 = 0;
    int max = -1000000000;
    int index_x = -1;
    int index_y = -1;
    while (r1 < n * m)
    {
        int t;
        cin >> t;
        if (t > max)
        {
            max = t;
            index_x = r1 % m;
            index_y = r1 / m;
        }
        r1++;
    }
    index_x++;
    index_y++;

    int area1 = (index_x) * (index_y);
    int area2 = (index_y) * (m + 1 - index_x);
    int area3 = (index_x) * (n + 1 - index_y);
    int area4 = (n + 1 - index_y) * (m + 1 - index_x);

    vector<int> values = {area1, area2, area3, area4};
    if (n == 1 && m == 1)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << *max_element(values.begin(), values.end()) << '\n';
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
