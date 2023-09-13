// Problem: B. Make it Divisible by 25
// Contest: Codeforces - Codeforces Round 748 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1593/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: key observation is treat the number as a string,
// now everything is almost constant. BruteForce
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int min(int a, int b)
{
    return a < b ? a : b;
}

void Solve()
{
    string S;
    cin >> S;

    int answer = 20;
    for (int i = S.size() - 1; i >= 0; i--)
    {
        int ops = S.size() - 1 - i;
        if (S[i] == '0')
        {
            int more = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (S[j] == '0')
                {
                    answer = min(answer, ops + more);
                }
                else if (S[j] == '5')
                {
                    answer = min(answer, ops + more);
                }
                else
                {
                    more++;
                }
            }
        }
        if (S[i] == '5')
        {
            int more = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (S[j] == '2')
                {
                    answer = min(answer, ops + more);
                }
                else if (S[j] == '7')
                {
                    answer = min(answer, ops + more);
                }
                else
                {
                    more++;
                }
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
