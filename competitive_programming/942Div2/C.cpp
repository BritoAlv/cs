// Problem: C. Permutation Counting
// Contest: Codeforces - Codeforces Round 942 (Div. 2)
// URL: https://codeforces.com/contest/1972/problem/C
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    int n;
    ull k;
    cin >> n >> k;
    vector<ull> a(n, 0);
    forn
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ull sum = 0;
    int i = 1;
    for (; i < n; i++)
    {
        if (sum + i * (a[i] - a[i - 1]) <= k)
        {
            sum += i * (a[i] - a[i - 1]);
        }
        else
        {
            break;
        }
    }
    for (int j = 0; j < i; j++)
    {
        a[j] = a[i - 1];
    }
    k -= sum;
    priority_queue<ull, vector<ull>, greater<ull>> pq;
    forn
    {
        pq.push(a[i]);
    }
    while (k > 0)
    {
        vector<ull> smallers;
        smallers.pb(pq.top());
        pq.pop();
        while (pq.sz > 0 && pq.top() == smallers[0])
        {
            smallers.pb(pq.top());
            pq.pop();
        }
        ull upper_add = k;
        if (pq.sz > 0)
        {
            upper_add = min(upper_add, pq.top() - smallers[0]);
        }
        ull to_add = min(upper_add, k / smallers.sz);
        ull rem = k % smallers.sz;
        for (auto &x : smallers)
        {
            x += to_add;
            k -= to_add;
            if (rem > 0 && to_add < upper_add)
            {
                x++;
                k -= 1;
                rem--;
            }
            pq.push(x);
        }
    }
    forn
    {
        a[i] = pq.top();
        pq.pop();
    }
    ull ans = -(n - 1) + a[0] * n;
    for (int i = 1; i < n; i++)
    {
        ans += a[i] > a[0];
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}