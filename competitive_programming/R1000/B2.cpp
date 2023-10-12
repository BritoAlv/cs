#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

// iterate over y values because those are only 100
// Programmer's idea.

long long get_min(long long C, long long A)
{
    return (A - C) / 100 + ((A - C) % 100 != 0);
}

long long get_max(long long C, long long B)
{
    return (B - C) / 100;
}

void Solve()
{
    int n;
    cin >> n;
    long long a[n];
    long long sum = 0;
    forn
    {
        cin >> a[i];
        sum += a[i];
    }

    set<int> answer;
    for (int percent = 0; percent <= 100; percent++)
    {
        long long already_copied = 0;
        forn
        {
            long long min1 = get_min(0, percent * a[i]);
            long long max1 = get_max(0, percent * a[i] + (a[i] - 1));

            long long min2 = get_min(100 * already_copied, sum * percent);
            long long max2 = get_max(100 * already_copied, sum * percent + (sum - 1));

            long long min3 = max(min1, min2);
            long long max3 = min(max1, max2);

            if (min3 <= max3)
            {
                answer.insert(percent);
            }

            already_copied += a[i];
        }
    }
    for (auto x : answer)
    {
        cout << x << endl;
    }
    return;
}

int main()
{
    Solve();
    return 0;
}