// Problem: B. Luke is a Foodie
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/B
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

void Solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int answer = 0;
    int index = 0;
    bool flag = true;
    while (flag)
    {
        int min = a[index];
        int max = a[index];
        for (int i = index; i <= n; i++)
        {
            if (i == n)
            {
                answer++;
                flag = false;
                break;
            }
            if (a[i] < min)
            {
                min = a[i];
            }
            if (a[i] > max)
            {
                max = a[i];
            }
            if (max - min > 2 * k)
            {
                index = i;
                answer++;
                break;
            }
        }
    }
    cout << answer - 1 << endl;
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
