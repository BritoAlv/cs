// Problem: B. Groups
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
    int n;
    cin >> n;
    vector<vector<int>> table;
    forn
    {
        table.push_back(vector<int>(5));
        for (int j = 0; j < 5; j++)
        {
            cin >> table[i][j];
        }
    }
    int exist = 0;
    for (int l = 0; l < 5; l++)
    {
        for (int j = l + 1; j < 5; j++)
        {
            int only_side1 = 0;
            int only_side2 = 0;
            int count1 = 0;
            int count2 = 0;
            int both_sides = 0;
            forn
            {
                only_side1 += table[i][l] && !table[i][j];
                only_side2 += !table[i][l] && table[i][j];
                both_sides += table[i][l] && table[i][j];
                count1 += table[i][l];
                count2 += table[i][j];
            }
            int total = n / 2;
            if (only_side1 <= total && only_side2 <= total)
            {
                if (both_sides == (total - only_side1) + (total - only_side2))
                {
                    exist = 1;
                }
            }
        }
    }
    if (exist)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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
