// Problem: A. Alfajores
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int N, M;
    cin >> N >> M;
    int queries[N];
    vector<int> emp_count;
    for (int i = 0; i < N; i++)
    {
        cin >> queries[i];
    }
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        if (emp_count.size() == 0 || emp_count.back() > x)
        {
            emp_count.push_back(x);
        }
    }
    reverse(emp_count.begin(), emp_count.end());
    for (int i = 0; i < N; i++)
    {
        int x = queries[i];
        while (x >= emp_count[0])
        {
            auto it = lower_bound(emp_count.begin(), emp_count.end(), x);
            if (it == emp_count.end() || *it > x)
            {
                --it;
            }
            if (*it)
            {
                x %= *it;
            }
            else
            {
                break;
            }
        }
        cout << x << ' ';
    }

    return;
}

int main()
{
    Solve();
    return 0;
}
