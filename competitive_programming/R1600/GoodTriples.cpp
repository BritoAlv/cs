// Problem: E. Good Triples
// Contest: Codeforces - Codeforces Round 913 (Div. 3)
// URL: https://codeforces.com/contest/1907/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

int dig_sum(int x)
{
    int answer = 0;
    while (x > 0)
    {
        answer += x % 10;
        x /= 10;
    }
    return answer;
}

long long answer[10];

long long Solve2(int n)
{
    if (n < 10)
    {
        return answer[n];
    }
    if (n % 10 == 0)
    {
        return Solve2(n / 10);
    }
    else
    {
        return Solve2(n - n % 10) * answer[n % 10];
    }
}

void Solve()
{
    int n;
    cin >> n;
    cout << Solve2(n) << endl;
    return;
}

int main()
{
    for (int i = 0; i <= 9; i++)
    {
        answer[i] = 0;
    }
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int l = 0; l <= 9; l++)
            {
                int exp_num = i + j + l;
                if (exp_num <= 9 && dig_sum(exp_num) == dig_sum(i) + dig_sum(j) + dig_sum(l))
                {
                    answer[exp_num]++;
                }
            }
        }
    }
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
