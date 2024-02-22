// Problem: C. Make Equal Again
// Contest: Codeforces - Codeforces Round 925 (Div. 3)
// URL: https://codeforces.com/contest/1931/problem/C
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

int get_ans(vector<int> a)
{
    int n = a.size();
    vector<int> checked(n, 0);
    checked[0] = 1;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[0])
        {
            checked[i] = 1;
            count++;
        }
        else
        {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (!checked[i] && a[i] == a[0])
        {
            count++;
            checked[i] = 1;
        }
        else
        {
            break;
        }
    }
    return n - count;
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn
    {
        cin >> a[i];
    }
    int ans1 = get_ans(a);
    reverse(a.begin(), a.end());
    int ans2 = get_ans(a);
    cout << min(ans1, ans2) << endl;
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
