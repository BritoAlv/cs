#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

long long compute_beauty(int n, long long a[], long long b[])
{
    long long sum = 0;
    forn
    {
        sum += abs(a[i] - b[i]);
    }
    return sum;
}

long long BruteForceSolve(int n, long long a[], long long b[])
{
    vector<int> index;
    forn
    {
        index.pb(i);
    }
    long long maxx = compute_beauty(n, a, b);
    long long original = maxx;
    for (auto i : index)
    {
        for (int j = 0; j < n; j++)
        {
            long long modify = abs(a[i] - b[i]) + abs(a[j] - b[j]);
            long long temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            maxx = max(maxx, original - modify + abs(a[i] - b[i]) + abs(a[j] - b[j]));
            b[j] = b[i];
            b[i] = temp;
        }
    }
    return maxx;
}

void Solve()
{
    int n, m;
    cin >> n;
    m = n;
    long long a[n];
    long long b[n];
    forn
    {
        cin >> a[i];
    }
    pair<long long, long long> cc[n];
    forn
    {
        cin >> b[i];
        cc[i] = {min(a[i], b[i]), i};
    }
    vector<long long> index;
    sort(cc, cc + n);

    index.pb(cc[0].second);
    index.pb(cc[n - 1].second);

    long long maxx = compute_beauty(n, a, b);
    long long original = maxx;
    for (auto i : index)
    {
        form
        {
            long long modify = abs(a[i] - b[i]) + abs(a[j] - b[j]);
            long long temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            maxx = max(maxx, original - modify + abs(a[i] - b[i]) + abs(a[j] - b[j]));
            b[j] = b[i];
            b[i] = temp;
        }
    }
    cout << maxx << endl;
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