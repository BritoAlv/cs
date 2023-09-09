// Problem: B. Array Cloning Technique
// Contest: Codeforces - Codeforces Round 781 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1665/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: make the array equal to the number that
// appears most number of times.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)

using namespace std;

int test_cases;

int get_i(int n, int d)
{
    int answer = 0;
    int t = d;
    while (n - t > 0)
    {
        t *= 2;
        answer++;
    }
    return answer;
}

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
    int max = 1;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            count++;
        }
        else
        {
            if (count > max)
            {
                max = count;
            }
            count = 1;
        }
    }
    if (count > max)
    {
        max = count;
    }
    cout << n - max + get_i(n, max) << endl;
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
