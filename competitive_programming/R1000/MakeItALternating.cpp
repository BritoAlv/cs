// Problem: C. Make it Alternating
// Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1879/problem/C
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

int test_cases;

long long factorials[2 * 100001];

void init()
{
    factorials[0] = 1;
    for (int i = 1; i < 2 * 100001; i++)
    {
        factorials[i] = (factorials[i - 1] * i) % 998244353;
    }
}

void Solve()
{
    string S;
    cin >> S;
    char last = S[0];
    int index = 0;
    int block_len = 0;
    int answer = 0;
    vector<int> block_lens;
    while (index < S.size())
    {
        if (S[index] == last)
        {
            block_len++;
        }
        else
        {
            if (block_len >= 2)
            {
                answer += (block_len - 1);
                block_lens.push_back(block_len - 1);
            }
            block_len = 1;
            if (index + 1 == S.size())
            {
                break;
            }
            else
            {
                last = S[index];
            }
        }
        index++;
    }
    if (block_len >= 2)
    {
        answer += (block_len - 1);
        block_lens.push_back(block_len - 1);
    }

    long long sec_answer = factorials[answer];
    for (auto x : block_lens)
    {
        sec_answer = (sec_answer * (x + 1)) % 998244353;
    }
    cout << answer << wp << sec_answer << endl;
    return;
}

int main()
{
    init();
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}