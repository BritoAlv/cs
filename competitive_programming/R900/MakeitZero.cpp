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
    if (n % 2 == 0)
    {
        cout << 2 << endl;
        cout << 1 << wp << n << endl;
        cout << 1 << wp << n << endl;
    }
    else
    {
        cout << 4 << endl;
        cout << 1 << wp << n - 1 << endl;
        cout << 1 << wp << n - 1 << endl;
        cout << (n - 1) << wp << n << endl;
        cout << (n - 1) << wp << n << endl;
    }
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
