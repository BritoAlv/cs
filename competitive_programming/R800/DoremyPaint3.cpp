// Problem: A. Doremy's Paint 3
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/contest/1890/problem/A
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

void Solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> count;
    forn
    {
        int a;
        cin >> a;
        if (count.find(a) == count.end())
        {
            count[a] = 0;
        }
        count[a]++;
    }
    if (count.size() > 2)
    {
        cout << "No" << endl;
    }
    else
    {
        if (count.size() == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            int first = (*(count.begin())).second;
            for (auto x : count)
            {
                if (abs(x.second - first) > 1)
                {
                    cout << "No" << endl;
                    return;
                }
            }
            cout << "Yes" << endl;
        }
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
