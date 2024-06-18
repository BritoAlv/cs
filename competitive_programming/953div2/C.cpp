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

int largest_solve(int n, long long k)
{
    for (long long i = 1; i < n + 2; i++)
    {
        if (i % 2 == 1)
        {
            if (2 * (i / 2) * (i / 2 + 1) >= k)
            {
                return i;
            }
        }
        else
        {
            if (2 * i / 2 * i / 2 >= k)
            {
                return i;
            };
        }
    }
    return -1;
}
void Solve()
{
    int n;
    long long k;
    cin >> n >> k;
    long long kk = 0;
    int n_prime = largest_solve(n, k);
    if (n_prime == -1 || k % 2 || n_prime > n)
    {
        cout << "No" << endl;
        return;
    }
    vector<int> a(n_prime, 0);
    for (int i = n_prime - 2; i >= 0; i--)
    {
        a[i] = (n_prime)-i - 1;
        kk += abs(a[i] - (i + 1));
    }
    a[n_prime - 1] = n_prime;
    for (int i = 0; i < n_prime; i++)
    {
        long long new_k = kk - abs(a[i] - (i + 1)) + abs(n_prime - (i + 1)) + abs(a[i] - n_prime);
        if (new_k == k)
        {
            int temp = a[i];
            a[n_prime - 1] = temp;
            a[i] = n_prime;
            break;
        }
    }
    cout << "Yes" << endl;
    vector<int> ans;
    for (auto x : a)
    {
        ans.pb(x);
    }
    for (int i = n_prime; i < n; i++)
    {
        ans.pb(i + 1);
    }
    long long profit = 0;
    for (int i = 0; i < ans.sz; i++)
    {
        profit += abs(ans[i] - (i + 1));
        cout << ans[i] << wp;
    }
    cout << endl;
    // assert(profit == k && ans.sz == n);
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
