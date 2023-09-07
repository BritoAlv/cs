// Problem: A. Mainak and Array
// Contest: Codeforces - Codeforces Round 819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.com/problemset/problem/1726/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: you need to calm down, 4 wrong submissions, good testing
// by the way, have three cases.
// rotate whole array.
// put at beginning anything.
// put at end anything.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

int max(int a, int b)
{
    return (a > b ? a : b);
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int answer = a[n - 1] - a[0];
    for (int i = 0; i < n - 1; i++)
    {
        answer = max(answer, a[n - 1] - a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        answer = max(answer, a[i] - a[0]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        answer = max(answer, a[i] - a[i + 1]);
    }
    cout << answer << '\n';
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
