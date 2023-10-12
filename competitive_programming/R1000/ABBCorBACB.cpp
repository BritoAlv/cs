// Problem: G. ABBC or BACB
// Contest: Codeforces - Codeforces Round 898 (Div. 4)
// URL: https://codeforces.com/contest/1873/problem/G
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

int test_cases;

int solve_part(int start, int end, string &s)
{
    int a_state_count = 0;
    int b_state_count = 0;
    int min_as_count = 10000000;
    for (int i = start; i <= end; i++)
    {
        int j = i;
        while (j <= end && s[j] == s[i])
        {
            j++;
        }
        b_state_count += s[i] == 'B';
        a_state_count += s[i] == 'A';
        if (s[i] == 'A')
        {
            if (j - i < min_as_count)
            {
                min_as_count = j - i;
            }
        }
        i = j - 1;
    }

    if (b_state_count >= a_state_count)
    {
        return (end - start + 1) - b_state_count;
    }
    if (b_state_count == 0)
    {
        return 0;
    }
    return (end - start + 1) - b_state_count - min_as_count;
}

void Solve()
{
    string S;
    cin >> S;
    int answer = 0;
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = i; j < S.size(); j++)
        {
            if ((j == S.size() - 1) || (S[j] == S[j + 1] && S[j] == 'B'))
            {
                answer += solve_part(i, j, S);
                i = j;
                break;
            }
        }
    }
    cout << answer << endl;
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