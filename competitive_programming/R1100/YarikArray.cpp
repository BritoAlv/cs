#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int i = 0; i < m; i++)
#define pb push_back

using namespace std;

long long max_sum(int start, int end, long long a[])
{
    long long answ = a[start];
    long long psums[end - start + 1];
    psums[0] = a[start];
    for (int i = 1; i < end - start + 1; i++)
    {
        psums[i] = psums[i - 1] + a[start + i];
    }
    long long min_p_sums[end - start + 1];
    min_p_sums[0] = 0;
    for (int i = 01; i < end - start + 1; i++)
    {
        min_p_sums[i] = min(min_p_sums[i - 1], psums[i - 1]);
    }
    for (int i = 0; i < end - start + 1; i++)
    {
        answ = max(answ, psums[i] - min_p_sums[i]);
    }
    return answ;
}

void Solve()
{
    int n;
    cin >> n;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    long long ans = a[0];
    forn
    {
        int start = i;
        int end = i;
        while (end + 1 < n && abs(a[end + 1]) % 2 != abs(a[end]) % 2)
        {
            end++;
        }
        i = end;
        ans = max(ans, max_sum(start, end, a));
    }
    cout << ans << endl;
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
