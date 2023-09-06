// Problem: B. Death's Blessing
// Contest: Codeforces - Educational Codeforces Round 138 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1749/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: notice that at the end of the process all
// the ai will be sum, and leave for last monster with
// bigger bi, also notice that because always the row shrinks
// its optimal to kill monsters in corners, to ensure bi
// only goes to one monster.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        answer += a[i];
    }

    int max = -1;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] > max)
        {
            max = b[i];
            index = i;
        }
        answer += b[i];
    }
    answer -= b[index];
    cout << answer << '\n';
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
