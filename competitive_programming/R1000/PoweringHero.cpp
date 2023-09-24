// Problem: C1. Powering the Hero (easy version)
// Contest: Codeforces - Codeforces Round 855 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1800/C1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: well the thing is to put elements in a priority
// queue, that seems intuitive, but why it works, well at any moment
// the k-zero, we can put the greatest k elements found before, because
// we just put in that order, because that can be done at any moment, in
// particular it can be applied at the position of the last zero.
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
    int n;
    cin >> n;
    priority_queue<int> q;
    long long answer = 0;

    forn
    {
        int t;
        cin >> t;
        if (t > 0)
        {
            q.push(t);
        }
        else
        {
            if (q.size() > 0)
            {
                answer += q.top();
                q.pop();
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
