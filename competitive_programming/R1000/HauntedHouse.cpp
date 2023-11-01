// Problem: B. Haunted House
// Contest: Codeforces - Codeforces Round 904 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1884/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: spent three hours without looking at the 0's' moving
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<char> S(n);
    vector<long long> costs;
    int need_zero = 0;
    long long a[n];
    forn
    {
        cin >> S[n - 1 - i];
        a[i] = 0;
    }
    forn
    {
        if (S[i] == '0')
        {
            costs.push_back((i - need_zero) + (costs.size() > 0 ? costs.back() : 0));
            need_zero++;
        }
    }
    for (int i = 0; i < need_zero; i++)
    {
        a[i] = costs[i];
    }
    for (int i = need_zero; i < n; i++)
    {
        a[i] = -1;
    }
    forn
    {
        cout << a[i] << wp;
    }
    cout << endl;
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
