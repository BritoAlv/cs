// Problem: A. Koxia and Whiteboards
// Contest: Codeforces - Good Bye 2022: 2023 is NEAR
// URL: https://codeforces.com/contest/1770/problem/A
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
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> A;
    forn
    {
        int t;
        cin >> t;
        A.push(t);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        A.pop();
        A.push(t);
    }
    long long sum = 0;
    while (A.size() > 0)
    {
        sum += A.top();
        A.pop();
    }
    cout << sum << endl;
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
