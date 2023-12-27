// Problem: C. Elemental Decompress
// Contest: Codeforces - Codeforces Round 842 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1768/C
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
#define ull unsigned long long
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int q[n];
    set<int> seen_a;
    set<int> seen_q;
    priority_queue<pair<int, int>> pending_a;
    priority_queue<pair<int, int>> pending_q;
    forn
    {
        cin >> a[i];
        if (seen_a.find(a[i]) != seen_a.end())
        {
            q[i] = a[i];
            a[i] = 0;
            pending_a.push({q[i], i});
            seen_q.insert(q[i]);
        }
        else
        {
            seen_a.insert(a[i]);
            q[i] = 0;
            pending_q.push({a[i], i});
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (seen_a.find(i) == seen_a.end())
        {
            if (pending_a.size() == 0)
            {
                cout << "NO" << endl;
                return;
            }
            auto next = pending_a.top();
            pending_a.pop();
            if (next.first < i)
            {
                cout << "NO" << endl;
                return;
            }
            a[next.second] = i;
        }

        if (seen_q.find(i) == seen_q.end())
        {
            if (pending_q.size() == 0)
            {
                cout << "NO" << endl;
                return;
            }
            auto next = pending_q.top();
            pending_q.pop();
            if (next.first < i)
            {
                cout << "NO" << endl;
                return;
            }
            q[next.second] = i;
        }
    }
    if (pending_a.size() == 0 && pending_q.size() == 0)
    {
        cout << "YES" << endl;
        forn
        {
            cout << a[i] << wp;
        }
        cout << endl;
        forn
        {
            cout << q[i] << wp;
        }
        cout << endl;
        return;
    }
    cout << "NO" << endl;
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
