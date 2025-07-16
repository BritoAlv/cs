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

void Solve()
{
    int n, k;
    cin >> n >> k;
    vl a(n);
    vl b(n);
    fori(0, n - 1) cin >> a[i];
    fori(0, n - 1) b[i] = a[i];
    sort(b.begin(), b.end());
    vl rem;
    fori(0, n - 1)
    {
        if (a[i] <= b[k - 1])
            rem.push_back(a[i]);
    }
    a = rem;
    n = a.size();
    int st = 0;
    int ed = n - 1;
    int ops = 0;
    while (n - ops >= k && st <= ed)
    {
        //cout << st << wp << ed << endl;
        if (a[st] == a[ed])
        {
            st++;
            ed--;
        }
        else
        {
            if (a[st] < a[ed])
            {
                if (a[ed] != b[k - 1])
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    ops++;
                    ed--;
                }
            }
            else
            {
                if (a[st] != b[k - 1])
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    ops++;
                    st++;
                }
            }
        }
    }
    vl rem2;
    fori(st, ed)
    {
        rem2.push_back(a[i]);
    }
    n = rem2.size();
    fori(0, n - 1) if (rem2[i] != rem2[n - 1 - i])
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
