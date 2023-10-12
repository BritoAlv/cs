// Problem: B. Going to the Cinema
// Contest: Codeforces - VK Cup 2022 - Отборочный раунд (Engine)
// URL: https://codeforces.com/contest/1781/problem/B
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
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int answer = 0;
    sort(a, a + n);
    int persons_going = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (persons_going == i + 1)
        {
            answer += (persons_going - 1 >= a[i]);
            persons_going--;
        }
        while (persons_going >= a[i])
        {
            persons_going--;
        }
    }
    bool works = true;
    forn
    {
        if (a[i] == 0)
        {
            works = false;
        }
    }
    answer += works;
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
