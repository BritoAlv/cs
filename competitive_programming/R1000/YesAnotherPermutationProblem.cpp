// Problem: C. Yet Another Permutation Problem
// Contest: Codeforces - Codeforces Round 893 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1858/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: just add i, 2*i
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
    int n;
    cin >> n;
    unordered_set<int> put_num;
    vector<int> nums;
    for (int mcd = 1; mcd <= n; mcd++)
    {
        if (put_num.find(mcd) != put_num.end())
        {
            continue;
        }
        else
        {
            int start = mcd;
            while (start <= n)
            {
                put_num.insert(start);
                nums.push_back(start);
                start *= 2;
            }
        }
    }
    forn
    {
        cout << nums[i] << wp;
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
