// Problem: D. Lucky Transformation
// Contest: Codeforces - Codeforces Beta Round 91 (Div. 2 Only)
// URL: https://codeforces.com/contest/122/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    int n, k;
    cin >> n >> k;
    vector<char> arr(n);
    forn
    {
        cin >> arr[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == '4' && arr[i + 1] == '7')
        {
            pq.push(i);
        }
    }
    while (k > 0 && pq.sz > 0)
    {
        int next = pq.top();
        pq.pop();
        if (next % 2 == 0)
        {
            arr[next] = '4';
            arr[next + 1] = '4';
            if (next + 2 < n && arr[next + 2] == '7')
            {
                if (k > 2)
                    k = k % 2 + 2;
                pq.push(next + 1);
            }
        }
        else
        {
            arr[next] = '7';
            arr[next + 1] = '7';
            if (next - 1 >= 0 && arr[next - 1] == '4')
            {
                if (k > 2)
                    k = k % 2 + 2;
                pq.push(next - 1);
            }
        }
        k--;
    }
    forn
    {
        cout << arr[i];
    }
    cout << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
