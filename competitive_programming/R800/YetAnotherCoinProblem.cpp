// Problem: B. Yet Another Coin Problem
// Contest: Codeforces - Codeforces Round 931 (Div. 2)
// URL: https://codeforces.com/contest/1934/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int ans[15];
void init()
{
    ans[0] = 0;
    ans[1] = ans[3] = ans[6] = ans[10] = 1;
    ans[2] = ans[4] = ans[7] = ans[9] = ans[11] = ans[12] = ans[13] = 2;
    ans[5] = ans[8] = ans[14] = 3;
}

int get_ans(int n)
{
    if (n < 0)
    {
        return 2e9 + 1;
    }
    else
    {
        return ans[n % 15];
    }
}

void Solve()
{
    int n;
    cin >> n;
    int ans1 = n / 15 + get_ans(n);
    int ans2 = 1 + (n - 10) / 15 + get_ans(n - 10);
    int ans3 = 2 + (n - 20) / 15 + get_ans(n - 20);
    cout << min(ans3, min(ans1, ans2)) << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
