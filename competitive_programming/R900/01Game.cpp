// Problem: B. 01 Game
// Contest: Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1373/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: check parity of min(one_count, zero_count)
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    string S;
    cin >> S;
    int zero_count = 0;
    int one_count = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '0')
        {
            zero_count++;
        }
        else
        {
            one_count++;
        }
    }

    cout << ((min(one_count, zero_count) % 2 == 0) ? "NET" : "DA") << '\n';
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
