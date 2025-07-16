// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

const int N = 100000 + 1;
int primes[N];

void init()
{
    fori(0, N - 1)
    {
        primes[i] = i;
    }
    fori(2, N - 1)
    {
        for (int j = 2 * i; j < N; j += i)
        {
            if (primes[j] == j)
            {
                primes[j] = i;
            }
        }
    }
}

int test_cases;
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    map<int, vi> groups;
    fori(2, n)
    {
        if (primes[i] == i)
        {
            groups[i] = vi();
        }
    }
    vi ans(n + 1);
    ans[1] = 1;
    fori(2, n)
    {
        groups[primes[i]].push_back(i);
    }
    map<int, int> pos;
    vector<int> pending;
    queue<vi> odd_groups;
    for (auto z : groups)
    {
        if (z.second.size() == 1)
        {
            int cur = z.second[0];
            pending.push_back(cur);
        }
        else
        {
            odd_groups.push(z.second);
        }
    }
    while (odd_groups.size() > 0)
    {
        vi next = odd_groups.front();
        odd_groups.pop();
        int s = next.size();
        fori(0, s - 1)
        {
            pos[next[(i + 1) % s]] = next[i];
            ans[next[i]] = next[(i + 1) % s];
        }
    }
    for (auto z : pending)
    {
        if (z <= n / 2)
        {
            ans[z] = 2 * z;
            int temp = ans[2 * z]; // ans[2 * z + 2] =  
            ans[2 * z] = z;
            ans[pos[2 * z]] = temp; // pos[2 * z] = 2 z + 2
        }
        else
        {
            ans[z] = z;
        }
    }
    fori(1, n)
    {
        cout << ans[i] << wp;
    }
    cout << endl;
}

int main()
{
    init();
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}