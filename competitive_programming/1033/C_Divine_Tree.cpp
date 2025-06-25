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

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

template <typename K, typename V> void print(const std::map<K, V> &m)
{
    for (const auto &[key, value] : m)
    {
        std::cout << key << ": " << value << "\n";
    }
}

int test_cases;
using namespace std;

vi vals;

void rec_solve(ll n, ll m)
{
    ll upper = (n * (n + 1)) / 2;
    if (n == 0)
    {
        return;
    }
    if (m > upper || m < n)
    {
        return;
    }
    if (m > 2 * (n - 1))
    {
        vals.push_back(n);
        m -= n;
        n--;
        rec_solve(n, m);
    }
    else
    {
        vals.push_back(m -(n-1));
        fori(0, n - 2)
        {
            vals.push_back(1);
        }
        return;
    }
}

void Solve()
{
    ll n, m;
    cin >> n >> m;
    vals.clear();
    rec_solve(n, m);
    if (vals.size() == n)
    {
        set<int> seen;
        fori(0, n-1){
            seen.insert(i + 1);
        }
        fori(0, n - 1)
        {
            seen.erase(vals[i]);
            if (vals[i] == 1)
            {
                forj(i + 1, n - 1)
                {
                    vals[j] = *seen.begin();
                    seen.erase(vals[j]);
                }
                break;
            }
        }
        cout << vals[0] << endl;
        fori(0, n-2){
            cout << vals[i] << wp << vals[i + 1] << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}
