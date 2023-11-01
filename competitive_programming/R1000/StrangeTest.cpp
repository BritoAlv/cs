#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int a, b;
    cin >> a >> b;
    int digits_b = 0;
    int start_b = b;
    while (start_b)
    {
        digits_b++;
        start_b /= 2;
    }
    int ans = min(b - a, (a | b) - b + 1);
    for (int k = b; k <= (1 << digits_b) - 1; k++)
    {
        int p = -1;
        for (int bit = 20; bit >= -1; bit--)
        {
            if (bit == -1)
            {
                ans = min(ans, (k - b) + 1);
            }
            if ((k & (1 << bit)) && !(a & (1 << bit)))
            {
                p = bit;
            }
            if (!(k & (1 << bit)) && (a & (1 << bit)))
            {
                int candidate = a + (1 << p) - (a % (1 << p));
                ans = min(ans, (k - b) + candidate - a + (candidate != k));
                break;
            }
        }
    }
    cout << ans << endl;

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
