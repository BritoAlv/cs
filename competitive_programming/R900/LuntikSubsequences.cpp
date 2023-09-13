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
    int cant_ones = 0;
    int cant_zeros = 0;
    while (n > 0)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            cant_ones++;
        }
        if (t == 0)
        {
            cant_zeros++;
        }
        n--;
    }
    long long answer = pow(2, cant_zeros);
    answer *= cant_ones;
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
