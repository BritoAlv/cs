// Problem: A. String Building
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1671/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
    string S;
    cin >> S;
    vector<int> lens;
    for (int i = 0; i < S.size(); i++)
    {
        int end_i = i;
        while (S[i] == S[end_i])
        {
            end_i++;
            if (end_i == S.size())
            {
                break;
            }
        }
        lens.push_back(end_i - i);
        i = end_i - 1;
    }
    for (int i = 0; i < lens.size(); i++)
    {
        if (lens[i] == 1)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
