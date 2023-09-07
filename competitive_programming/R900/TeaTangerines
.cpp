#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
notice that reducing the minimum is not optimal, so call it x then try to make all the tangerines in the interval [x, 2*x-1] because 2x is not allowed, now for some reason the best thing to do is for each number try to subtract (2*x-1) until falls in range. 
*/

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int min = 10000001;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 2 * min)
        {
            answer += a[i] / (2 * min - 1);
            if (a[i] % (2 * min - 1) == 0)
            {
                answer--;
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