// Problem: C. Random Events
// Contest: Codeforces - Codeforces Round 689 (Div. 2, based on Zed Code Competition)
// URL: https://codeforces.com/contest/1461/problem/C
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

void Solve()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int largest_index = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == i + 1)
        {
            largest_index--;
        }
        else
        {
            break;
        }
    }

    double answer = 0;
    double before_prob = 1;
    for (int i = 0; i < m; i++)
    {
        int index;
        double p;
        cin >> index >> p;
        if (index >= largest_index)
        {
            answer += p * before_prob;
            before_prob *= (1 - p);
        }
    }
    if (largest_index == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        printf("%0.15f \n", answer);
    }

    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
