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

int primes[1000001];

void init()
{
    primes[0] = 0;
    primes[1] = 1;
    primes[2] = 2;
    for (int i = 2; i < 1000001; i++)
    {
        primes[i] = i;
    }
    for (int i = 2; i < 1000001; i++)
    {
        if (primes[i] == i)
        {
            for (int j = 2 * i; j < 1000001; j += i)
            {
                if (primes[j] == j)
                {
                    primes[j] = i;
                }
            }
        }
    }
}

set<int> get_primes(int n)
{
    set<int> result;
    while (n > 1)
    {
        result.insert(primes[n]);
        n /= primes[n];
    }
    return result;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    set<int> valids;
    vector<pair<int, int>> pp(1000001, {-1, -1});
    forn
    {
        set<int> primess = get_primes(a[i]);
        for (auto x : primess)
        {
            if (pp[x].first == -1)
            {
                pp[x] = {i, i};
            }
            else if (pp[x].second + 1 == i)
            {
                pp[x].second++;
            }
            else
            {
                pp[x] = {i, i};
            }

            if (pp[x].first >= 0 && pp[x].second - pp[x].first + 1 >= k)
            {
                valids.insert(x);
            }
        }
    }
    if (valids.size() == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << *(valids.rbegin()) << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    init();
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
