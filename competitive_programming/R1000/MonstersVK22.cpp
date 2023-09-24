// Problem: A. Monsters (easy version)
// Contest: Codeforces - VK Cup 2022 - Финальный раунд (Engine)
// URL: https://codeforces.com/problemset/problem/1784/A
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Math Proof: trick was with repeated numbers, how do not understimated
// // the problem
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
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }

    sort(a, a + n);
    long long answer = 0;
    int last_obtained = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= last_obtained)
        {
            answer += a[i] - last_obtained;
            last_obtained++;
        }
        else
        {
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