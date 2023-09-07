// Problem: B. Ugu
// Contest: Codeforces - Codeforces Round 830 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1732/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: got accepted using greedy but don't'
// know why ?, i think that the idea is that contiguos blocks
// with the same number don't affect, so imagine string is
// 0101, or 1010, there should be done one step by each
// change of number.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

int solve(string &s, int start, bool to_zero)
{
    char check_one = '0';
    char check_two = '1';
    if (!to_zero)
    {
        check_one = '1';
        check_two = '0';
    }

    long unsigned int index = start;
    while (index < s.size() && s[index] == check_one)
    {
        index++;
    }

    if (index == s.size())
    {
        return 0;
    }
    else
    {
        while (index < s.size() && s[index] == check_two)
        {
            index++;
        }
        if (index == s.size())
        {
            return 0;
        }
        else
        {
            return 1 + solve(s, index, !to_zero);
        }
    }
}

void Solve()
{
    int n;
    cin >> n;
    string S;
    cin >> S;
    cout << solve(S, 0, true) << '\n';
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
