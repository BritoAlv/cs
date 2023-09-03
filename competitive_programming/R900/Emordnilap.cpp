// Problem: B. Emordnilap
// Contest: Codeforces - Codeforces Round 845 (Div. 2) and ByteRace 2023
// URL: https://codeforces.com/problemset/problem/1777/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
    Math Proof: the total of inversions along n!
    permutations can be calculated recursively.
*/

#include <bits/stdc++.h>

using namespace std;

int test_cases;

long long factorial[100000 + 1];
long long inversions[100000 + 1];
long long MOD = 1000000007;

void Solve()
{
    long long n;
    cin >> n;
    long long answer = 2 * inversions[n];
    answer += (factorial[n] * ((n * (n - 1)) / 2)) % MOD;
    answer %= MOD;
    cout << answer << '\n';
    return;
}

int main()
{
    factorial[0] = 1;
    inversions[0] = 0;
    for (int i = 1; i < 100000 + 1; i++)
    {
        factorial[i] = (i * factorial[i - 1]) % MOD;
        inversions[i] = factorial[i - 1];

        if (i % 2 == 0)
        {
            inversions[i] *= (i / 2);
            inversions[i] %= MOD;
            inversions[i] *= (i - 1);
            inversions[i] %= MOD;
        }
        else
        {
            inversions[i] *= ((i - 1) / 2);
            inversions[i] %= MOD;
            inversions[i] *= (i);
            inversions[i] %= MOD;
        }
        inversions[i] += (i * inversions[i - 1]) % MOD;
        inversions[i] %= MOD;
    }
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
